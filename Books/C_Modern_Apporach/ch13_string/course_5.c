//
// Created by Administrator on 2023/2/28.
//

#include <stdio.h>
#include <string.h>

#define MAX_REMINDER_SIZE 60
#define MSG_SIZE 60

int read_line(char *, int);

int read_line(char s[], int n) {
  int count = 0, ch;
  while ((ch = getchar()) != '\n') {
	if (count < n)
	  s[count++] = ch;
  }
  s[count] = '\0';
  return count;
}

/*
 *
 * 月提醒列表：
 * 按日期排序，输入0打印,打印格式如下
 *      day reminder
 *        5 task1
 *        9 task2
 *       15 task3
 *       25 task4
 */
int main() {
  //1.按日期从小到大提示 day msg,其中day右对其，msg左对其
  //2.超过MAX_REMINDER_SIZE,不能录入
  //3.输入0时候显示所有内容
  char reminders[MAX_REMINDER_SIZE][MSG_SIZE + 3];//保存
  char day_str[3], remind_msg[MSG_SIZE + 1];//日期字串 消息字串
  int day_number = 0, msg_count = 0;

  char s1[10] = "abc", s2[10] = "xyz";
  strcpy(s1, s2);//xyz
  strcat(s1, s2);//xyzxyz
  printf("%lld", strlen(s2));
  for (;;) {

	if (msg_count > MAX_REMINDER_SIZE) {
	  puts("+++++++++++ No space left++++++++");
	  break;
	}
	printf("Enter a day and reminder:");
	scanf("%2d", &day_number);
	if (day_number == 0) {
	  break;
	}
	//读入前两位数字并保存到
	sprintf(day_str, "%2d", day_number);
	//读取指定长度字符
	read_line(remind_msg, MSG_SIZE);
	//按日期小到大排
	int i = 0, j = 0;
	//从0行开始，找到按日期大小排的位置i
	for (i = 0; i < msg_count; i++) {
	  if (strcmp(day_str, reminders[i]) < 0)
		break;
	}
	// 如果i的位置是小于当前msg总数，则将此条msg插入i行，i行后面的往后挪一行
	for (j = msg_count; j > i; j--) {
	  strcpy(reminders[j], reminders[j - 1]);//将j-1行挪到j行
	}
	//复制日期到行
	strcpy(reminders[i], day_str);
	//拼接msg到后面
	strcat(reminders[i], remind_msg);
	msg_count++;
  }

  printf("day reminder\n");
  for (int i = 0; i < msg_count; ++i) {
	printf(" %s\n", reminders[i]);
  }
  return 0;
}