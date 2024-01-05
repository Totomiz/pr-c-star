//
// Created by Lenovot on 2024/1/4.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <errno.h>
#include <string.h>


void printf_stat(struct stat sb) {
    printf("File type:                ");

    switch (sb.st_mode & S_IFMT) {
        case S_IFBLK:
            printf("block device\n");
            break;
        case S_IFCHR:
            printf("character device\n");
            break;
            //if(S_ISDIR(sb.st_mode))
        case S_IFDIR:
            printf("directory\n");
            break;
        case S_IFIFO:
            printf("FIFO/pipe\n");
            break;
        case S_IFLNK:
            printf("symlink\n");
            break;
        case S_IFREG:
            printf("regular file\n");
            break;
        case S_IFSOCK:
            printf("socket\n");
            break;
        default:
            printf("unknown?\n");
            break;
    }

    printf("I-node number:            %ld\n", (long) sb.st_ino);

    printf("Mode:                     %lo (octal)\n",
           (unsigned long) sb.st_mode);

    printf("Link count:               %ld\n", (long) sb.st_nlink);
    printf("Ownership:                UID=%ld   GID=%ld\n",
           (long) sb.st_uid, (long) sb.st_gid);

    printf("Preferred I/O block size: %ld bytes\n",
           (long) sb.st_blksize);
    printf("File size:                %lld bytes\n",
           (long long) sb.st_size);
    printf("Blocks allocated:         %lld\n",
           (long long) sb.st_blocks);

    printf("Last status change:       %s", ctime(&sb.st_ctime));
    printf("Last file access:         %s", ctime(&sb.st_atime));
    printf("Last file modification:   %s", ctime(&sb.st_mtime));

}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s dir_name\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    DIR *dir;
    struct dirent *dirent;
    if ((dir = opendir(argv[1])) == NULL) {
        fprintf(stderr, "can't open %s\n", argv[1]);
    }

    //change working directory ,如果没有这行，测试读取其他目录不完整
    if (chdir(argv[1]) == -1) {
        fprintf(stderr, "can't chdir to '%s': %s\n", argv[1], strerror(errno));
        exit(EXIT_FAILURE);
    }

    while ((dirent = readdir(dir)) != NULL) {

        printf("FileName : %s\n", dirent->d_name);
        struct stat sb;
        //lstat(dirent->d_name,&sb);
        if (stat(dirent->d_name, &sb) == -1) {
            perror("lstat");
            exit(EXIT_FAILURE);
        }
        printf_stat(sb);

        printf("\n\n\n\n");
    }
}