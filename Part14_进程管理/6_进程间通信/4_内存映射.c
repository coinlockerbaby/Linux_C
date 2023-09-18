#include <fcntl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int
main ()
{
  // 因为mmap函数的返回值是一个地址所以这边先定义一个地址
  void *addr;
  int fd = open ("test.txt", O_RDWR);
  if (fd < 0)
    {
      perror ("open");
      exit (0);
    }
  addr = mmap (NULL, 128, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
  if (addr == MAP_FAILED)
    {
      perror ("mmap");
      exit (0);
    }
  // 尝试对文件映射的内存区域进行写数据
  memcpy (addr, "hello", 5);
}