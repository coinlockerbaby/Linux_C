#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>


int
main ()
{
  int ret;
  int fd;
  char buf[32];
  // 创建有名管道
  ret = mkfifo("myfifo.txt", 0666);
  if (ret < 0)
  {
    perror ("mkfifo");
    return 0;
  }
  // 只写打开有名管道
  fd = open ("myfifo.txt", O_WRONLY);
  if (fd < 0)
    {
      perror ("open");
      return 0;
    }
  while (1)
    {
      fgets (buf, 32, stdin);
      write (fd, buf, strlen (buf));
    }
}