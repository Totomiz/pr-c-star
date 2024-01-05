//
// Created by Lenovot on 2023/12/29.
//

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <sysexits.h>
#include <errno.h>


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
            //execlp执行失败才会执行下面的输出
            printf("parent pid = %d ,child pid = %d \n",getppid(),getpid());
            fprintf(stderr, "shell: couldn't exec %s: %s\n", buff,
                    strerror(errno));
            exit(EX_UNAVAILABLE);
        }
//        if (pid > 0) {
        printf("pid before: %d\n",pid);
        pid_t wait_Pid = waitpid(pid, &status, 0);
        printf("pid wait_Pid: %d\n",wait_Pid);
//        }
        printf("%% ");
    }
    exit(EXIT_SUCCESS);
}