#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
int
main ()
{
  DIR *dp; // 目录流指针
  struct dirent *dt;
  dp = opendir ("testdir");
  if (dp == NULL)
    {
      perror ("opendir");
      return 0;
    }
  while ((dt = readdir (dp)) != NULL)
    {
      printf ("%s\n", dt->d_name);
    }
  closedir (dp);
}