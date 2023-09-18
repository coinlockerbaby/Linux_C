#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void
handler (int sig)
{
  int states;
  wait (&states);
  printf ("wait retv = %d\n", WEXITSTATUS (states));
}

int
main ()
{
  pid_t pid;
  pid = fork ();
  struct sigaction act;
  act.sa_handler = handler;
  act.sa_flags = 0;
  sigemptyset (&act.sa_mask);

  if (pid < 0)
    {
      perror ("fork");
    }
  else if (pid == 0) // 子进程
    {
      sleep (5);
      exit (0);
    }
  else if (pid > 0) // 父进程
    {
      sigaction (SIGCHLD, &act, NULL); // 捕捉SIGCHID
      while (1)
        {
          printf ("this is father process!\n");
          sleep (1);
        }
    }
}