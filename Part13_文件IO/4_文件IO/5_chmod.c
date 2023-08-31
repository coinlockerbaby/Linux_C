#include <stdio.h>
#include <sys/stat.h>

int
main()
{
  int ret;
  ret = chmod ("test.txt", 0444);
  if (ret < 0)
    {
      perror ("chmod");
      return 0;
    }
  printf ("chmod success!\n");
}