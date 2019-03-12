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

struct acct {
    double balance;
    int numTransactions;
};

int main( int argc, char *argv[]){
    if( argc != 3) {
        fprintf( stderr, "Incorrect argument count");
        exit( EXIT_FAILURE);
    }

    FILE *accountDB = fopen( argv[1], "r");
    FILE *transFile = fopen( argv[2], "r");


}
