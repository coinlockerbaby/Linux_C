#include <fcntl.h>
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
  void *addr;
  int fd;
  fd = open ("test.txt", O_RDWR);
  if (fd < 0)
    {
      perror ("open");
      return 0;
    }
  int len = lseek (fd, 0, SEEK_END);
  addr = mmap (NULL, 2048, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
  if (addr == MAP_FAILED)
    {
      perror ("mmap");
      return 0;
    }
  close (fd);
  while (1)
    {
      printf ("read = %s\n", (char *)addr);
      sleep (1);
    }
}