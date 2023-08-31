#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int
main ()
{
  FILE *fp;
  time_t ctime;
  int linecount = 0;
  struct tm *ctimestr;
  char *buf = malloc (32);
  fp = fopen ("time.txt", "a+");
  if (fp == NULL)
    {
      perror ("fopen");
      fclose (fp);
      return 0;
    }

  // 计算行号
  while (fgets (buf, 32, fp)) // 通过按行读取函数,读取成功行号+1
    {
      if (buf[strlen (buf) - 1] == '\n') // 判断读取的是不是一整行
        {
          linecount++;
        }
    }

  while (1)
    {
      ctime = time (NULL);
      ctimestr = localtime (&ctime);
      printf ("%d, %04d-%02d-%02d %02d:%02d:%02d\n", linecount,
              ctimestr->tm_year + 1900, ctimestr->tm_mon + 1,
              ctimestr->tm_mday, ctimestr->tm_hour, ctimestr->tm_min,
              ctimestr->tm_sec);
      fprintf (fp, "%d, %04d-%02d-%02d %02d:%02d:%02d\n", linecount,
               ctimestr->tm_year + 1900, ctimestr->tm_mon + 1,
               ctimestr->tm_mday, ctimestr->tm_hour, ctimestr->tm_min,
               ctimestr->tm_sec);
      fflush (fp);
      linecount++;
      sleep (1);
    }
  fclose (fp);
  return 0;
}