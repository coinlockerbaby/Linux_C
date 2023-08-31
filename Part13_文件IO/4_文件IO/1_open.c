#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int
main ()
{
  int fd; // 文件描述符
  int ret;
  fd = open ("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
  if (fd < 0)
    {
      printf ("open file failed !\n");
      return 0;
    }
  printf ("open file success! fd = %d\n", fd);
  // 下面的程序用来证明 close之后的fd不是设备描述符，再次close会发生错误
  ret = close (fd);
  if (ret < 0)
    {
      printf ("close failed!\n");
    }
  ret = close (fd);
  printf ("ret = %d\n", ret);
}