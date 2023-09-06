#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int
main ()
{
  pid_t pid;
  pid = fork ();
  if (pid < 0)
    {
      perror ("fork");
      return 0;
    }
  else if (pid > 0)
    {
      exit (0);
    }
  printf ("i am daemon process\n");
  printf ("sid = %d pid = %d pgid = %d\n", getsid (getpid ()), getpid (),
          getpgid (getpid ()));
  // 创建新的会话
  if (setsid () < 0)
    {
      perror ("setsid");
      exit (0);
    }
  printf ("after sid = %d pid = %d pgid = %d\n", getsid (getpid ()), getpid (),
          getpgid (getpid ()));
  // 更改当前工作目录
  chdir ("/");
  // 重设文件权限掩码
  if (umask < 0)
    {
      perror ("umask");
      exit (-1);
    };
  // 关闭打开的文件描述符
  for (int i = 0; i < 3; i++)
    {
      close (i);
    }
}