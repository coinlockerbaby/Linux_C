#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <netinet/in.h>

#define SERV_PORT 5001
#define SERV_IP_ADDR  "192.168.7.246"

int
main ()
{
  int fd; // 套接字文件描述符
  int ret;
  struct sockaddr_in sin; // 地址结构体
  // 1.创建套接字
  fd = socket (AF_INET, SOCK_STREAM, 0); //TCP 套接字
  if (fd < 0)
    {
      perror ("socket");
      exit (1);
    }
  bzero (&sin, sizeof (sin));
  sin.sin_family = AF_INET; // IPV4
  sin.sin_port = htons (SERV_PORT);
  //sin.sin_addr.s_addr = inet_addr (SERV_IP_ADDR);
  ret = inet_pton (AF_INET, SERV_IP_ADDR, sin.sin_addr.s_addr);
  if (ret != 1)
    {
      perror ("inet_pton");
      exit (1);
    }
  // 2.用bind给套接字绑定地址和端口
  ret = bind (AF_INET, &sin, sizeof (sin));
  if (ret < 0)
    {
      perror ("bind");
      exit (1);
    }
  // 3.调用listen 把主动套接字变成被动套接字
  // 4.阻塞等待客户端的连接请求

}