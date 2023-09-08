#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int
main ()
{
  int pfd[2]; // pfd 是文件描述符 pfd[0]是读端，pfd[1] 是写端
  char buff[32];
  int re;
  pid_t pid;
  // 创建管道
  re = pipe (pfd);
  if (re < 0)
    {
      perror ("pipe");
      return 0;
    }
  pid = fork (); // 创建子进程
  if (pid < 0)
    {
      perror ("fork");
    }
  else if (pid == 0) //  如果是子进程
    {
      while (1)
        {
          strcpy (buff, "hello world");
          write (pfd[1], buff, strlen (buff) + 1);
          sleep (1);
        }
    }
  else //  如果是父进程
    {
      while (1)
        {
          re = read (pfd[0], buff, 32);
          if (re > 0)
            {
              printf ("read pipe=%s\n", buff);
            }
        }
    }
}