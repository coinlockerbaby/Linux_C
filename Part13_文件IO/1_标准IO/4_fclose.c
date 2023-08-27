#include <errno.h>
#include <stdio.h>
#include <string.h>

int
main ()
{
  FILE *fp;
  int fpret;
  fp = fopen ("1.txt", "r");
  if (fp == NULL)
    {
      printf ("fopen: %s\n", strerror (errno));
      perror ("fclose");
    }
  else
    {
      printf ("open file success!\n");
      fpret = fclose (fp);
      if (fpret == 0)
        printf ("file close success!\n");
      else
        perror ("fclose");
    }
}