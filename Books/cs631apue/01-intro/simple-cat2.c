//
// Created by Lenovot on 2023/12/25.
//

/*
 * Stripped down version of 'cat', using unbuffered I/O.
 * ./simple-cat  simple-cat.c
 *
 * Guess what, this is also a primitive version of 'cp':
 * ./simple-cat simple-cat.c >simple-cat.copy
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Invalid input: Usage %s <FILE>", argv[0]);
        exit(EXIT_FAILURE);
    }
    int fd = open(argv[1], O_RDONLY);
    char bf[BUFSIZ];
    size_t n;
    while ((n = read(fd, bf, BUFSIZ)) > 0) {
        if (write(STDOUT_FILENO, bf, n) != n) {
            fprintf(stderr, "Unable to write: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }
    }
    if (n < 0) {
        fprintf(stderr, "Unable to read: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    return 0;
}