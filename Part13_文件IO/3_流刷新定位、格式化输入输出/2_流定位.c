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
  fwrite ("abcde", 5, 1, fp);
  fseek (fp, -2, SEEK_END);
  fwrite ("hahaha", 6, 1, fp);
  fclose (fp);
  return 0;
}