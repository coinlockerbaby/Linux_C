#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

/***********由于我比较懒代码中有众多地方没有判断返回值，请不要养成这种习惯*************/

int
main ()
{
  int fd; // 文件描述符
  char *buff = malloc (128);
  if (buff == NULL)
    {
      printf ("malloc failed!\n");
      return 0;
    }
  memset (buff, 0, 128);
  fd = open ("test.txt", O_RDWR | O_CREAT | O_APPEND, 0666);
  if (fd < 0)
    {
      printf ("open file failed!\n");
      return 0;
    }
  printf ("open file success!\n");
  read (fd, buff, 128);
  printf ("%s\n", buff); // 打印读取的数据
  memset (buff, 0, 128);
  strcpy (buff, " yuanshen qidong!");
  write (fd, buff, strlen (buff));
  memset (buff, 0, 128);
  lseek (fd, 0, SEEK_SET);
  read (fd, buff, 128);
  printf ("%s\n", buff);
  close (fd);
  free (buff);
}