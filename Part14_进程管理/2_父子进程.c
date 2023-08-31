#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main ()
{
  pid_t pid;
  pid = fork ();
  if (pid > 0)
    {
      printf ("this is father process\n");
      printf ("pid = %d\n", pid);
      while (1)
        {
          sleep (1);
          printf ("father sleep\n");
        }
    }
  else if (pid == 0)
    {
      printf ("this is child process\n");
      printf ("pid = %d\n", pid);
      while (1)
        {
          sleep (1);
          printf ("child sleep\n");
        }
    }
  else if (pid < 0)
    {
      perror ("fork");
    }
}