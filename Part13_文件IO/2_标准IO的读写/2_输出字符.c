#include <stdio.h>

int
main()
{
  FILE *fp = fopen ("2.txt", "a+");
  if (fp == NULL)
    {
      perror ("fopen:");
      return 0;
    }
  int rec = fputc ('a', fp);
  if (rec == -1)
    {
      perror ("fputc");
      fclose (fp);
      return 0;
    }
}