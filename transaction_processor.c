/*
Created by Philippe Nadon on 2019-03-11.
1. Open the database file and a transaction file (the one passed to it by name via the 'exec' system call)
2. Read each line of the transaction file
3. modify the database by updating the transaction count and the balance for the account
 referenced by number in the transaction file.
*/

// fscanf returns 2 if 2 items successfully scanned
// check transFile return file, test with faulty file

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
const in OPEN_ERROR = -1;

int main(int argc, char *argv[]) {

    int id;
    int db;
    double transAmount;
    int bytesRead;
    FILE *transFile;

    char buf[BUFFER_SIZE];
    int accSize = sizeof(struct acct_data);

    if (argc != 3) {
        fprintf(stderr, "Incorrect argument count");
        exit(EXIT_FAILURE);
    }
    if ((db = open(argv[1], O_RDWR)) == OPEN_ERROR) {
        perror("Failed to open database file\n");
        exit(EXIT_FAILURE);
    }
    if ((transFile = fopen(argv[2], "r")) == NULL) {
        perror("Failed to open transaction file\n");
        exit(EXIT_FAILURE);
    }

    rewind(transFile);
    while (fscanf(transFile, "%d%lf", &id, &transAmount) != EOF) {
        lseek(db, accSize * id, SEEK_SET);
        bytesRead = read(db, &acct_data, accSize);
        lseek(db, -bytesRead, SEEK_CUR);

        if (bytesRead < 0) {
            perror("Error reading database file");
            exit(EXIT_FAILURE);
        } else if (bytesRead == 0) {
            acct_data.transactions = 0;
            acct_data.balance = 0;
        }
        acct_data.balance += transAmount;
        acct_data.transactions++;
        write(db, &acct_data, accSize);
    }

    fclose(transFile);
    if (close(db) < 0) {
        perror("Failed to close db File");
        exit(EXIT_FAILURE);
    }

    return 0;
}
