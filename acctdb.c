/*
acctdb.c

Philippe Nadon
AUCSC 380
March 15, 2019

Description:
    A program which takes a database file and multiple transaction files,
    and uses child processes to read the transaction files
    and update the database file.

PROGRAM STEPS:
1. parses the command-line arguments;
2. tries to open the database file that was named as the first command-line
    argument, and creates it if it doesn't exist;
3. creates a child process for each transaction file named on the command line
    (if any), passing it the name of the binary database file
    and one of the transaction files (a text file);
4. waits for each child process to finish, and displays its exit status when it
    does;
5. prints a summary of the account data from the database file,
    showing the transaction count and balance for all accounts that have a
    non-zero transaction count.

If no transaction files are listed on the command line, the parent process only
    does steps 1, 2, and 5 (i.e., just prints a summary of the current data
    in the account database).
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "acctdb.h"

struct acct_data {
    unsigned transactions;
    double balance;
} acct_data;

const int OPEN_ERROR = -1;

void exit_status(int status);
void printRes( char *dbFileArg, int accSize);

int main(int argc, char *argv[]) {
    int dbFile;
    int stat;
    pid_t pid;
    char *dbFileArg = argv[1];
    int accSize = sizeof(acct_data);
    char *exec_process = "./transaction_processor";

    if (argc < 2) {
        fprintf(stderr,
                "Please specify the database file\n");
        exit(EXIT_FAILURE);
    }
    if ((dbFile = open( dbFileArg, O_RDWR | O_CREAT, S_IWUSR | S_IRUSR)) < 1) {
        perror("Error creating or opening database file");
        exit(EXIT_FAILURE);
    } else {
        close(dbFile);
    }

    for (int i = 2; i < argc; i++) {
        if ((pid = fork()) < 0) {
            perror("Forking child process failed!");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            fprintf(stdout, "Forked child %d: %d\n", i - 1, getpid());
            execlp(exec_process,
                   exec_process,
                   dbFileArg,
                   argv[i],
                   (char *) NULL);
        }
    }
    if (pid > 0) {
        for (int i = 2; i < argc; i++) {
            pid = wait(&stat);
            fprintf(stdout, "Terminated child %d: %d, ", i - 1, pid);
            exit_status(stat);
        }
    }
    printRes( dbFileArg, accSize);

    return 0;
}

void exit_status(int status) {
    if (WIFEXITED(status))
    printf("normal termination - exit status = %d\n",
    WEXITSTATUS(status));
    else if (WIFSIGNALED(status)) {
    printf("abnormal termination - signal number = %d",
    WTERMSIG(status));
    if (WCOREDUMP(status))
    printf(" (core dumped)");
    printf("\n");
    } else if (WIFSTOPPED(status))
    printf("child stopped - signal number = %d\n",
    WSTOPSIG(status));
}

void printRes( char *dbFileArg, int accSize) {
    int bytesRead;
    int dbFile;

    unsigned totalTransactions = 0;
    double totalBalances=  0;
    int id = 0;

    if( (dbFile = open( dbFileArg, O_RDONLY)) == OPEN_ERROR) {
        perror("Failed to open database file");
        exit(EXIT_FAILURE);
    }
    while( read( dbFile, &acct_data, accSize) != 0) {
        if ( bytesRead < 0) {
            perror("Error reading database file");
            exit( EXIT_FAILURE);
        }
        else if( acct_data.transactions != 0) {
          totalTransactions += acct_data.transactions;
            totalBalances += acct_data.balance;
            printf("%4d%10d%14.2lf\n",
                   id,
                   acct_data.transactions,
                   acct_data.balance);
        }
        id++;
    }
    printf("          ----     ---------\n");
    printf("%14d%14.2lf\n", totalTransactions, totalBalances);
}
