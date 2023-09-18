#include <linux/posix_types.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void
handler (int sig)
{
  printf ("hello world\n");
}

int
main ()
{
  struct sigaction act;
  act.sa_handler = handler;
  act.sa_flags = 0;
  sigemptyset (&act.sa_mask);
  sigaction (SIGINT, &act, NULL);

  while (1)
    {
      pause ();
    }
}