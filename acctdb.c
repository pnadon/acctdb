#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "acctdb.h"

/*
ssize_t write(
        int fd,
        const void *buf,
        size_t count
        );

ssize_t read(
        int fd,
        void *buf,
        size_t count
        );
*/
int main() {

    struct acct_data {
        unsigned transactions;
        double balance;
    } acct_data;

    ssize_t write(
            int fd,
            const void *buf,
            size_t count
    );

    pid_t pid;
    pid = fork();
    switch (pid) {
        case -1:
            fatalsys("fork failed");
            break;

        case 0: //child
            childFunc();
            break;

        default: // parent

    }

    return 0;
}

void childFunc() {
    _exit();
}