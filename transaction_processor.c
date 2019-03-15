/*
Created by Philippe Nadon on 2019-03-11.
1. Open the database file and a transaction file (the one passed to it by name via the 'exec' system call)
2. Read each line of the transaction file
3. modify the database by updating the transaction count and the balance for the account
 referenced by number in the transaction file.
*/

#include <stdio.h>
#include <stdlib.h>
#include "transaction_processor.h"
#include <fcntl.h>
#include <unistd.h>

struct acct_data {
  unsigned transactions;
  double balance;
} acct_data;

const int BUFFER_SIZE = 1024;

int main( int argc, char *argv[]){

  printf("argv[1]: %s, argv[2]: %s\n",  argv[1], argv[2]);
  char buf[ BUFFER_SIZE];
  int accSize = sizeof( struct acct_data);
  int id;
  double transAmount;
  int bytesRead;

  printf("In transaction_processor.c\nstruct size:%d\n", accSize);
  if( argc != 3) {
    fprintf( stderr, "Incorrect argument count");
    exit( EXIT_FAILURE);
  }

  int db;
  if( (db = open( argv[1], O_RDWR)) == -1){
    perror("Failed to open database file\n");
  }
  FILE *transFile;

  if(( transFile = fopen( argv[2], "r")) == NULL){
    perror("Failed to open transaction file\n");
    return 1;
  }
  printf("At while\n");

  rewind( transFile);
  while( fscanf( transFile, "%d%lf", &id, &transAmount) != EOF){
    printf("Found in trans: id=%d, amount=%lf\n", id, transAmount);
    lseek( db, accSize * id, SEEK_SET);
    printf("lseek'd to %d\n",  accSize * id);

    bytesRead = read( db, &acct_data, accSize);
    lseek( db, -bytesRead, SEEK_CUR);

    printf("bytes read from db: %d\n", bytesRead);
    printf("initial trans:%d, and balance:%lf\n", acct_data.transactions, acct_data.balance);
    if ( bytesRead < 0){
      perror("Error reading database file");
      exit( EXIT_FAILURE);
    }
    else if ( bytesRead == 0){
      acct_data.transactions = 0;
      acct_data.balance = 0;
    }
    printf("Prior acct transaction:%d, and balance:%f\n", acct_data.transactions, acct_data.balance);

    acct_data.balance += transAmount;
    acct_data.transactions++;
    printf("After acct transaction:%d, and balance:%f\n", acct_data.transactions, acct_data.balance);

    write( db, &acct_data, accSize);
  }
  printf("done while\n");
  fclose( transFile);
  if( close( db) < 0){
    perror("Failed to close db File");
    exit( EXIT_FAILURE);
  }

  exit( EXIT_SUCCESS);
}
