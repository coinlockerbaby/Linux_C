#include <stdio.h>
#include <stdlib.h>

int
main ()
{
  FILE *fp;
  fp = fopen ("1.txt", "w");
  if (fp == NULL)
    {
      perror ("fopen");
      fclose (fp);
      return 0;
    }
  fwrite ("hello", 5, 1, fp);
  fflush (fp);
  while (1)
    ;
}