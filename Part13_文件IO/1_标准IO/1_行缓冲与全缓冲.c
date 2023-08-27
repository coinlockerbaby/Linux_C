#include <stdio.h>
#include <unistd.h>
int
main ()
{
  for (int i = 0; i < 1024; i++)
    printf ("a");
  while (1)
    {
      sleep (1);
    }
}