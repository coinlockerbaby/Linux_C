#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

int
main ()
{
  pid_t pid;
  for (int i = 0; i < 5; i++)
    {
      pid = fork ();
      if (pid < 0)
        {
          perror ("fork");
        }
      else if (pid == 0)
        {
          printf ("child process\n");
          sleep (5);
          break;
        }
      else if (pid > 0)
        {
          printf ("father process\n");
          sleep (1);
        }
    }
  while (1)
    {
      sleep (1);
    }
}