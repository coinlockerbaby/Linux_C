#include <stdio.h>
#include <stdlib.h>

int
main ()
{
  FILE *fp;
  char *buff;
  size_t ret;
  fp = fopen ("1.txt", "r");
  if (fp == NULL)
    {
      perror ("fopen");
      fclose (fp);
      return 0;
    }
  buff = malloc (sizeof (char) * 100);
  if (buff == NULL)
    return 0;
  ret = fread (buff, 10, 1, fp);
  if (ret == -1)
    {
      perror ("fread");
      goto end;
    }
  printf ("buff = %s\n", buff);
end:
  free (buff);
  fclose (fp);
}