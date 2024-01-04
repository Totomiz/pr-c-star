//
// Created by Lenovot on 2023/12/29.
//

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>


int main(int argc, char *args[]) {
    char buff[BUFSIZ];
    pid_t pid;
    int status;
    printf("%% ");
    while (fgets(buff, BUFSIZ, stdin) != NULL) {
        if (buff[strlen(buff) - 1] == '\n')
            buff[strlen(buff) - 1] = 0;
        pid = fork();
        if (pid == 0) {
            execlp(buff, buff, (char *) 0);
            exit(127);
        }
//        if (pid > 0) {
        waitpid(pid, &status, 0);
//        }
        printf("%% ");
    }
    exit(0);
}