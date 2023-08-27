#include <stdio.h>
#include <errno.h>
#include <string.h>

int
main ()
{
  FILE *fp;
  fp = fopen ("1.txt", "r");
  if (fp == NULL)
    {
      perror ("fopen:");
      return 0;
    }
  // 打开文件后会从第一个字符开始读
  // 读完一个读写指针往后移动
  int rec = fgetc(fp);
  printf ("Get char = %c\n", rec);
  rec = fgetc(fp);
  printf ("Get char = %c\n", rec);
}
