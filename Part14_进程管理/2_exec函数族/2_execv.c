#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main ()
{
  char *argv[] = { "ls", "-a", "-l", "./", NULL };
  if (execv ("/bin/ls", argv) < 0)
    {
      perror ("execv");
    }
}