#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

int
main (int argc, const char *argv[])
{
  struct stat buf;
  int ret;
  ret = stat (argv[1], &buf);
  if (ret < 0)
    {
      perror ("stat");
      return 0;
    }
  // 判断文件类型
  if (S_ISREG (buf.st_mode))
    {
      printf ("-");
    }
  if (S_ISDIR (buf.st_mode))
    {
      printf ("d");
    }
  if (S_ISCHR (buf.st_mode))
    {
      printf ("c");
    }
  if (S_ISBLK (buf.st_mode))
    {
      printf ("b");
    }
  if (S_ISFIFO (buf.st_mode))
    {
      printf ("p");
    }
  // if (S_ISSOCK (buf->st_mode))
  //   {
  //     printf ("s");
  //   }
  for (int i = 8; i >= 0; i--)
    {
      if (buf.st_mode & (0x01 << i))
        {
          switch (i % 3)
            {
            case 2:
              printf ("r");
              break;
            case 1:
              printf ("w");
              break;
            case 0:
              printf ("x");
              break;
            }
        }
      else
        {
          printf ("-");
        }
    }
  printf (" %d ", (int)buf.st_size);
  struct tm *ctimestr = localtime (&buf.st_ctime); // ctime是最后一次改变的时间
  printf ("%04d-%02d-%02d %02d:%02d:%02d\n", ctimestr->tm_year + 1900,
          ctimestr->tm_mon + 1, ctimestr->tm_mday, ctimestr->tm_hour,
          ctimestr->tm_min, ctimestr->tm_sec);
}