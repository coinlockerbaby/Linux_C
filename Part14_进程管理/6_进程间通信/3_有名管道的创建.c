#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>



int
main ()
{
  int ret;
  int fd;
  // 创建有名管道
  ret = mkfifo("myfifo.txt", 0666);
  if (ret < 0)
  {
    perror ("mkfifo");
    return 0;
  }
  // 只写打开有名管道
  fd = open ("mkfifo.txt", O_WRONLY);
  if (fd < 0)
    {
      perror ("open");
      return 0;
    }

  
}