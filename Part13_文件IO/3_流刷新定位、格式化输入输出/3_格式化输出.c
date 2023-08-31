#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int
main ()
{
  char *buf = malloc (100);
  memset (buf, 0, sizeof (100));
  if (buf == NULL)
    {
      perror ("malloc");
      return 0;
    }
  int year = 2021;
  int month = 10;
  int day = 1;
  sprintf (buf, "%d-%d-%d", year, month, day);      // 格式化输出到数组
  fprintf (stdout, "%d-%d-%d\n", year, month, day); // 格式化输出到io流
  printf ("%s\n", buf);
}