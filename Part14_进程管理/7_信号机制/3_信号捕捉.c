#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void
handler (int sig)
{
  printf ("I catch the sig = %d\n", sig);
}

int
main ()
{
  signal (SIGINT, handler);
  while (1)
    {
      sleep (1);
    }
}