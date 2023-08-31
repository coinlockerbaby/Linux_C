#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int
main ()
{
  pid_t pid;
  printf ("before fork\n");
  pid = fork ();
  if (pid > 0)
    {
      printf ("this is father process\n");
      printf ("pid = %d\n", (int)pid);
    } 
  else if (pid == 0)
    {
      printf ("this is child process\n");
      printf ("pid = %d\n", (int)pid);
    }
  else if (pid < 0)
    {
      perror ("fork");
      return 0;
    }
}
