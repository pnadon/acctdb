/*
  acctdb.c

  Philippe Nadon
  AUCSC 380
  March 15, 2019

Description:
    Program called from acctdb, which opens a single transaction file,
    and updates the corresponding balances within the database file.

PROGRAM STEPS:
1. Open the database file and a transaction file
    (the one passed to it by name via the 'exec' system call)
2. Read each line of the transaction file
3. modify the database by updating the transaction count and the balance for
    the account referenced by number in the transaction file.
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

struct acct_data {
    unsigned transactions;
    double balance;
} acct_data;

const int BUFFER_SIZE = 1024;

// Potential error code returned by open();
const int OPEN_ERROR = -1;

const int NUM_REQUIRED_ARGS = 3;
const int RETURN_SUCCESS = 0;
const int DB_ARG = 1;
const int TRANS_ARG = 2;

void fatalsys(const char *msg);

int main(int argc, char *argv[]) {

    int id;
    int db;
    int lineNum = 1;
    double transAmount;
    int bytesRead;
    FILE *transFile;
    int numScanned;

    char buf[BUFFER_SIZE];
    int accSize = sizeof(struct acct_data);

    if (argc != NUM_REQUIRED_ARGS) {
        fprintf(stderr, "Incorrect argument count\n");
        exit(EXIT_FAILURE);
    }
    if ((db = open(argv[DB_ARG], O_RDWR)) == OPEN_ERROR) {
        fatalsys("Failed to open database file\n");
    }
    if ((transFile = fopen(argv[TRANS_ARG], "r")) == NULL) {
        fatalsys("Failed to open transaction file\n");
    }

    rewind(transFile);
    while ((numScanned = fscanf(transFile, "%d%lf", &id, &transAmount)) == 2) {
        lseek(db, accSize * id, SEEK_SET);
        bytesRead = read(db, &acct_data, accSize);
        lseek(db, -bytesRead, SEEK_CUR);

        if (bytesRead < 0) {
            fatalsys("Error reading database file");
        } else if (bytesRead == 0) {
            acct_data.transactions = 0;
            acct_data.balance = 0;
        }
        acct_data.balance += transAmount;
        acct_data.transactions++;
        write(db, &acct_data, accSize);
        lineNum++;
    }
    if (numScanned != EOF) {
        fprintf(stderr, "Incorrect entry on line %d \n", lineNum);
        exit(EXIT_FAILURE);
    }

    if (fclose(transFile) == EOF) {
        fatalsys("Failed to close transaction file");
    }
    if (close(db) < 0) {
        fatalsys("Failed to close db File");
    }

    return RETURN_SUCCESS;
}

/*
 * Wrapper for perror() and exit(EXIT_FAILURE), for code neatness.
 */
void fatalsys(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}
