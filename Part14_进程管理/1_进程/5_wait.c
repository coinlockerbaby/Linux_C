#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int
main ()
{
  pid_t pid;
  int status;
  pid_t ret_pid;
  pid = fork ();
  if (pid == 0)
    {
      sleep (1);
      printf ("child will exit\n");
      exit (2);
    }
  else if (pid > 0)
    {
      ret_pid = wait (&status);
      printf ("get child status = %d\n", WEXITSTATUS (status));
    }
  else if (pid < 0)
    {
      perror ("fork");
      return 0;
    }
  while (1)
    {
      sleep (1);
    }
}