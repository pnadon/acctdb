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

/*
 * The data structure which represents a user's account.
 * transactions = number of transactions performed on account.
 * balance = the user's account balance, can be negative.
 */
struct acct_data {
    unsigned transactions;
    double balance;
} acct_data;

// Potential error code returned by open();
const int OPEN_ERROR = -1;

const int MIN_ARGS = 2;
const int DB_ARG = 1;
const int FIRST_TRANS_FILE_ARG = 2;
const int PARENT_PID = 0;
const int RETURN_SUCCESS = 0;

void fatalsys(const char *msg);

void exit_status(int status);

void printRes(char *dbFileArg, int accSize);

int main(int argc, char *argv[]) {
    int dbFile;
    int stat;
    pid_t pid;
    char *dbFileArg = argv[DB_ARG];
    int accSize = sizeof(acct_data);
    char *exec_process = "./transaction_processor";

    if (argc < MIN_ARGS) {
        fprintf(stderr,
                "Please specify the database file\n");
        exit(EXIT_FAILURE);
    }
    if ((dbFile = open(dbFileArg, O_RDWR | O_CREAT, S_IWUSR | S_IRUSR)) < 1) {
        fatalsys("Error creating or opening database file");
    } else {
        close(dbFile);
    }

    for (int i = FIRST_TRANS_FILE_ARG; i < argc; i++) {
        if ((pid = fork()) < PARENT_PID) {
            fatalsys("Forking child process failed!");
        } else if (pid == PARENT_PID) {
            fprintf(stdout, "Forked child %d: %d\n", i - 1, getpid());
            execlp(exec_process,
                   exec_process,
                   dbFileArg,
                   argv[i],
                   (char *) NULL);
        }
    }
    if (pid > PARENT_PID) {
        for (int i = FIRST_TRANS_FILE_ARG; i < argc; i++) {
            pid = wait(&stat);
            fprintf(stdout, "Terminated child %d: %d, ", i - 1, pid);
            exit_status(stat);
        }
    }
    printRes(dbFileArg, accSize);

    return RETURN_SUCCESS;
}

/*
 * Parses the status flag retrieved from the terminated child process.
 * Can determine how it terminated ( normally or otherwise).
 */
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

/*
 * Iterates through the database file and prints the transaction amounts,
 * and ending balances. Lastly, it prints the total of both.
 */
void printRes(char *dbFileArg, int accSize) {
    int bytesRead;
    int dbFile;

    unsigned totalTransactions = 0;
    double totalBalances = 0;
    int id = 0;

    if ((dbFile = open(dbFileArg, O_RDONLY)) == OPEN_ERROR) {
        fatalsys("Failed to open database file");
    }
    while (read(dbFile, &acct_data, accSize) != 0) {
        if (bytesRead < 0) {
            fatalsys("Error reading database file");
        } else if (acct_data.transactions != 0) {
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

/*
 * Wrapper for perror() and exit(EXIT_FAILURE), for code neatness.
 */
void fatalsys(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}
