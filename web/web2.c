#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <winsock2.h> // Windows下需要引入Winsock库
#else
#include <sys/socket.h>
    #include <arpa/inet.h>
#endif
#define PORT 80
int main() {
#ifdef _WIN32
  WSADATA wsa;
  if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
	printf("Failed. Error Code : %d", WSAGetLastError());
	return 1;
  }
#endif

  int server_fd, new_socket;
  struct sockaddr_in address;

  char *hello = "HTTP/1.1 200 OKContent-Type: text/plainContent-Length:12Hello, World!";

  // 创建套接字文件描述符
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
	perror("socket failed");
	exit(EXIT_FAILURE);
  }
  memset(&address, '0', sizeof(address));

  address.sin_family = AF_INET;
  address.sin_addr.s_addr = htonl(INADDR_ANY);
  address.sin_port = htons(PORT);
  // 绑定端口号和IP地址
  if (bind(server_fd,(struct sockaddr *)&address,sizeof(address))<0)
  {
	perror("bind failed");
	exit(EXIT_FAILURE);
  }
  // 监听客户端请求
  if (listen(server_fd, SOMAXCONN) == -1)
  {
	perror("listen failed");
	exit(EXIT_FAILURE);
  }
  printf("Server started on port %d...", PORT);
  while(1){
	// 接受客户端连接请求并创建新的套接字文件描述符
	if ((new_socket=accept(server_fd,NULL,NULL))==-1){
	  perror("accept failed");
	  continue;
	}
	send(new_socket , hello , strlen(hello) , 0 );

	close(new_socket); // 关闭连接
  }
  return EXIT_SUCCESS;
}