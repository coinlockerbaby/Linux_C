#include <stdio.h>
#include <stdlib.h>
#define BUFFER_MAX_LEN 100
int
main ()
{
  FILE *fp;
  char *buffer = malloc (sizeof (char) * BUFFER_MAX_LEN);
  char *ret;
  fp = fopen ("1.txt", "r");
  if (fp == NULL)
    {
      perror ("fopen");
      fclose (fp);
      return 0;
    }
  // ret = fgets (buffer, 5, stdin); // 从标准输入获取数据
  // 把每行数据都输入，然后输出到stdout
  for (int i = 0; i < 3; i++)
    {
      ret = fgets (buffer, 10, fp);
      if (ret == NULL)
        {
          perror ("fgets");
          fclose (fp);
          return 0;
        }
      printf ("buffer = %s", buffer);
    }
  printf ("\n");
  free (buffer)
}