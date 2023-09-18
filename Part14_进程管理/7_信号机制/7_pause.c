#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void
handler (int sig)
{
  printf ("i get sig = %d\n", sig);
}

void
my_task ()
{
  printf ("my task start\n");
  sleep (3);
  printf ("my task end\n");
}

int
main ()
{

  struct sigaction act;
  act.sa_handler = handler;
  act.sa_flags = 0;
  sigemptyset (&act.sa_mask);
  sigaction (SIGINT, &act, NULL);
  sigset_t set, set2; // 信号集  阻塞信号防止mytask被打断
  sigemptyset (&set2);
  sigaddset (&set, SIGINT);
  pause ();
  // printf ("after pause\n");
  while (1)
    {
      sigprocmask (SIG_BLOCK, &set, NULL);
      my_task ();
      // sigsuspend (&set2);
      sigprocmask (SIG_UNBLOCK, &set, NULL);
      pause ();
    }
}