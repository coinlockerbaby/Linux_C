#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main ()
{
  system ("ls -a -l ./");
  printf ("hello world\n");
}