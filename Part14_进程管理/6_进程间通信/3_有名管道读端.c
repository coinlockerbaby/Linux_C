#include <fcntl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int
main ()
{
  int ret;
  int fd;
  char buf[32];

  fd = open ("myfifo.txt", O_RDONLY);
  if (fd < 0)
    {
      perror ("open");
      return 0;
    }
  while (1)
    {
      memset (buf, 0, 32);
      ret = read (fd, buf, 32);
      if (ret > 0)
        {
          printf ("read fifo = %s", buf);
        }
      else if (ret == 0) // 如果读到文件末尾
        {
          exit (0); // 退出进程
        }
    }
}
