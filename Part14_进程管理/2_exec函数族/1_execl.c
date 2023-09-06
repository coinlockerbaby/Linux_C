#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main()
{
  if (execl ("/bin/ls", "ls", "-a", "-l", "./", NULL) < 0)
    {
      perror ("execl");
    }
  return 0;
}