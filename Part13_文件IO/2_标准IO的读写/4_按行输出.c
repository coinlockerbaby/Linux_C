#include <stdio.h>
#include <stdlib.h>

int
main ()
{
  FILE *fp;
  int ret;
  fp = fopen ("1.txt", "a+");
  if (fp == NULL)
    {
      perror ("fopen");
      fclose (fp);
      return 0;
    }
  ret = fputs ("hello\nworld\n", fp);
  if (ret == -1)
    {
      perror ("fputs");
      fclose (fp);
      return 0;
    }
  fclose (fp);
  return 0;
}
