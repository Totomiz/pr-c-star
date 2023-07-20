//
// Created by Administrator on 2023/6/6.
//


#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysmacros.h>

int
main(int argc, char *argv[]) {
  struct stat sb;

  if (argc != 2) {
	fprintf(stderr, "Usage: %s <pathname>\n", argv[0]);
	exit(EXIT_FAILURE);
  }

  if (lstat(argv[1], &sb) == -1) {
	perror("lstat");
	exit(EXIT_FAILURE);
  }

  printf("ID of containing device:  [%lx,%lx]\n",
         (long) major(sb.st_dev), (long) minor(sb.st_dev));

  printf("File type:                ");

  // switch (sb.st_mode & S_IFMT) {
  // case S_IFBLK: printf("block device\n");
  //   break;
  // case S_IFCHR: printf("character device\n");
  //   break;
  // case S_IFDIR: printf("directory\n");
  //   break;
  // case S_IFIFO: printf("FIFO/pipe\n");
  //   break;
  // case S_IFLNK: printf("symlink\n");
  //   break;
  // case S_IFREG: printf("regular file\n");
  //   break;
  // case S_IFSOCK: printf("socket\n");
  //   break;
  // default: printf("unknown?\n");
  //   break;
  // }

# define S_ISSOCK(mode) __S_ISTYPE((mode), __S_IFSOCK)
  if (S_ISREG(sb.st_mode))
	printf("regular file\n");
  else if (S_ISDIR(sb.st_mode))
	printf("directory\n");
  else if (S_ISCHR(sb.st_mode))
	printf("character special\n");
  else if (S_ISBLK(sb.st_mode))
	printf("block special\n");
  else if (S_ISFIFO(sb.st_mode))
	printf("FIFO\n");
  else if (S_ISLNK(sb.st_mode))
	printf("symbolic link\n");
  else if (S_ISSOCK(sb.st_mode))
	printf("socket\n");
  else
	printf("unknown\n");

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

  exit(EXIT_SUCCESS);
}
