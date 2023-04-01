//
// Created by Administrator on 2023/3/15.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <winsock2.h> // Windows下需要引入Winsock库
#include <stdint.h>
#include <process.h>
#include <io.h>

#include <iphlpapi.h>
#include <icmpapi.h>
#else
#include <sys/socket.h>
    #include <arpa/inet.h>
#endif
#define PING_PKT_SIZE 64

// IP报头结构体
struct ipheader {
  unsigned char      iph_ihl:5, /* 版本号 */
  iph_ver:4; /* 首部长度 */
  unsigned char      iph_tos;   /* 服务类型 */
  unsigned short int iph_len;   /* 总长度 */
  unsigned short int iph_ident; /* 标识符 */
  unsigned short int iph_flag:3,/* 标志位 */
  iph_offset:13;/* 分片偏移量 */
  unsigned char	   ip_ttl;
  unsigned char	   protocol;
  unsigned short int checksum;
  struct in_addr	   source_ip;
  struct in_addr	   dest_ip;
};

// ICMP报文结构体
struct icmpheader {
  uint8_t type;       // 报文类型（8表示回显请求）
  uint8_t code;       // 代码（0表示正常）
  uint16_t checksum;  // 校验和
  uint16_t id;        // ID标识符（可以自定义）
  uint16_t seq_num;   // 序列号（可以自定义）
};

uint16_t compute_checksum(uint16_t *buf, int len) {
  uint32_t sum = 0;
  while (len > 1) {
	sum += *buf++;
	len -= sizeof(uint16_t);
  }
  if (len)
	sum += *(uint8_t *) buf;
  sum = (sum >> 16) + (sum & UINT32_C(0xffff));
  sum += (sum >> 16);
  return ~((uint16_t) sum);
}
int main(int argc, char **argv){

#ifdef _WIN32
  WSADATA wsaData;
  if(WSAStartup(MAKEWORD(2,2),&wsaData)!=0){
	printf("Failed. Error Code : %d", WSAGetLastError());
	return EXIT_FAILURE;;
  }
#endif

  if(argc!=2){
	printf("Usage : %s [destination IP]", argv[0]);
	exit(EXIT_FAILURE);;
  }
  char* target_ip_str=argv[1];
  unsigned long target_ip=inet_addr(target_ip_str);
  int sockfd = socket(AF_INET, SOCK_RAW , IPPROTO_ICMP);
  if(sockfd<0){
	perror("socket");
	exit(EXIT_FAILURE);;
  }
  struct sockaddr_in servaddr={};
  servaddr.sin_family = AF_INET;
  memcpy(&servaddr.sin_addr.s_addr,&target_ip,sizeof(target_ip));
  char ping_pkt[PING_PKT_SIZE]={};
  memset(ping_pkt,'\xAA',sizeof(ping_pkt));
  struct icmpheader *icmp_hdr=(struct icmpheader*)ping_pkt;
  icmp_hdr->type=8;// 回显请求类型为8
  icmp_hdr->code=0;// 正常状态码为零
  icmp_hdr->id=getpid();// 使用进程ID作为标识符
  icmp_hdr->seq_num=htons(1);// 设置序列号
  // 计算校验和并填充到ICMP报文中
  icmp_hdr->checksum=compute_checksum((uint16_t*)ping_pkt,sizeof(struct icmpheader));
  ssize_t bytes_sent=-1;

  bytes_sent=sendto(sockfd,ping_pkt,sizeof(ping_pkt),1,(const struct sockaddr*)&servaddr,sizeof(servaddr));
  if(bytes_sent<=-1){
	perror("sendto");
	exit(EXIT_FAILURE);;
  }
  char recv_buf[sizeof(struct icmpheader)+sizeof(struct timeval)]={};
  ssize_t bytes_received=-1;
  bytes_received=read(sockfd,&recv_buf,sizeof(recv_buf));
  if(bytes_received<=-1){
	perror("read");
	exit(EXIT_FAILURE);
  }
  close(sockfd);
  printf("%s is alive!",target_ip_str);
  return EXIT_SUCCESS;;
}