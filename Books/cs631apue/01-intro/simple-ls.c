//
// Created by Lenovot on 2024/1/4.
//

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Invalid input: Usage %s <FILE>", argv[0]);
        exit(EXIT_FAILURE);
    }
    DIR *dir = opendir(argv[1]);
    struct dirent *dirent;
    while ((dirent = readdir(dir)) != NULL) {
        printf("%s\n", dirent->d_name);
    }
    return 0;
}