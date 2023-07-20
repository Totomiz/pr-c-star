//
// Created by Administrator on 2023/5/28.
//

#include "apue.h"

#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

/**
 * 计算当前打开的数量
 * @param num
 * @return
 */
int countOpenFiles(int num) {
  struct stat stats;
  int count = 0;
  for (int i = 0; i < num; i++) {
	if (fstat(i, &stats) == 0) { //获取文件状态信息
	  printf("Currently open: fd #%d (inode %ld)\n", i,
	         stats.st_ino);
	  count++;
	}
  }

  return count;
}

/**
 * 软设置当前进程能打开的FD数量最大值
 * @param softmax
 */
void setSoftLimitFdMax(int softmax){

  struct rlimit rlim;

  rlim.rlim_cur = softmax; //动态改变软限制值
  rlim.rlim_max = 1024;//硬设置最大值，参照前面的输出

  if (setrlimit(RLIMIT_NOFILE, &rlim) == -1) {
	perror("setrlimit");
	exit(EXIT_FAILURE);
  }

  printf("The new soft limit for the number of files is: %lld\n",
         (long long)rlim.rlim_cur);
}


void openFiles(int num) {
  int count, fd;

  count = countOpenFiles(num);

  printf("Currently open files: %d\n", count);

  for (int i = count; i <= num ; i++) {
	if ((fd = open("/dev/null", O_RDONLY)) < 0) {//对 虚空 /dev/null 继续打开
	  if (errno == EMFILE) {
		printf("Opened %d additional files, then failed: %s (%d)\n", i - count, strerror(errno), errno);
		break;
	  } else {
		fprintf(stderr, "Unable to open '/dev/null' on fd#%d: %s (errno %d)\n",
		        i, strerror(errno), errno);
		break;
	  }
	}
  }
}
int main(int argc,char *argv[]){
  int openmax=NULL;
#ifdef OPEN_MAX
  printf("OPEN_MAX is defined as %d.\n", OPEN_MAX);
#else
  printf("OPEN_MAX is not defined on this platform.\n"); //OPEN_MAX未被定义在此平台
#endif


  printf("'getconf OPEN_MAX' says: ");
  (void)fflush(stdout);
  (void)system("getconf OPEN_MAX"); // 打印getconf的值

  errno = 0;
  if((openmax= sysconf(_SC_OPEN_MAX))<0){ // 不合理场景
    if (errno == 0) {
	  fprintf(stderr, "sysconf(3) considers _SC_OPEN_MAX unsupported?\n");
    } else {
	  fprintf(stderr, "sysconf(3) error for _SC_OPEN_MAX: %s\n",
	          strerror(errno));
    }
    exit(EXIT_FAILURE);
  }
  printf("sysconf(3) says this process can open %ld files.\n", openmax);// 打印sysconf设置的值

  setSoftLimitFdMax(500); // 软设置

  struct rlimit rlp;
  if (getrlimit(RLIMIT_NOFILE, &rlp) != 0) { // Historically, this limit was named RLIMIT_OFILE on BSD
	fprintf(stderr, "Unable to get per process rlimit: %s\n", strerror(errno));
	exit(EXIT_FAILURE);
  }
  openmax = (int)rlp.rlim_cur;
  printf("getrlimit(2) says this process can open %d files.\n", openmax);

  openFiles(openmax);// 测试可打开文件数
  return 0;
}