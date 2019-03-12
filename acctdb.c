/*
Created by Philippe Nadon on 2019-03-11.

PROGRAM STEPS:
1. parses the command-line arguments;
2. tries to open the database file that was named as the first command-line argument,
 and creates it if it doesn't exist;
3. creates a child process for each transaction file named on the command line (if any),
 passing it the name of the binary database file and one of the transaction files (a text file);
4. waits for each child process to finish, and displays its exit status when it does;
5. prints a summary of the account data from the database file,
 showing the transaction count and balance for all accounts that have a non-zero transaction count.

If no transaction files are listed on the command line, the parent process only does steps 1, 2, and 5
 (i.e., just prints a summary of the current data in the account database).
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "acctdb.h"

int main( int argc, char *argv[]){
    char *dbFileArg = argv[1];

    if( argc < 2 ) {
        fprintf( stderr, "Please specify the database file, and transaction file(s)\n");
        exit( EXIT_FAILURE);
    }

    FILE *dbFile;

    if( access( dbFileArg, F_OK ) == -1 ) {
        dbFile = fopen( dbFileArg, "w");
        fclose( dbFile);
        fprintf( stdout, "Specified database doesn't exist. Created new database %s\n", dbFileArg);
    }

    pid_t pid;
    int status;
    char *exec_process = "./transaction_processor";

    for( int i = 2; (i < argc ) && pid != 0; i++){
        if (( pid = fork()) <  0){
            fprintf( stderr, "Forking child process failed!\n");
            exit( EXIT_FAILURE);
        }
        else if ( pid == 0) {
            fprintf( stdout, "Child %d: %d\n", i, getpid());
            execlp( exec_process, argv[1], argv[i]);
        }
    }
}