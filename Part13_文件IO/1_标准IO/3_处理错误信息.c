// 处理错误信息主要涉及两个函数
// perror和 strerror
// 以下是两种函数的使用方式

#include <stdio.h>
#include <string.h>
#include <errno.h>

// int
// main ()
// {
//   FILE *fp;
//   fp = fopen ("1.txt", "r");
//   if (fp == NULL)
//     perror ("fopen::");
//   else
//     printf ("open file success!\n");
// }

int
main ()
{
  FILE *fp;
  fp = fopen ("1.txt", "r");
  if (fp == NULL)
    {
      printf ("fopen: %s\n", strerror (errno));
    }
  else
    {
      printf ("open file success!\n");
    }
}