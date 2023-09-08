#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int
main ()
{
  pthread_t pid;
  int re;
  int pfd[2];
  char buf[32];
  memset (buf, 0, 32);
  re = pipe (pfd);
  if (re < 0)
    {
      perror ("pipe");
    }
  int i;
  for (i = 0; i < 2; i++)
    {
      pid = fork ();
      if (pid < 0)
        {
          perror ("fork");
        }
      else if (pid == 0)
        {
          break; // 防止子进程fork
        }
      else
        {
        }
    }

  //  用于读取的进程
  if (i == 2)
    {
      close (pfd[1]);
      while (1)
        {
          memset (buf, 0, 32);
          re = read (pfd[0], buf, 32);
          if (re > 0)
            {
              printf ("%s\n", buf);
            }
        }
      return 0;
    }
  // 用于写入的进程2
  if (i == 1)
    {
      close (pfd[0]);
      while (1)
        {
          strcpy (buf, "this is 2 process");
          write (pfd[1], buf, strlen (buf));
          usleep (700000);
        }
    }
  // 用于写入的进程1
  if (i == 0)
    {
      close (pfd[0]);
      while (1)
        {
          strcpy (buf, "this is 1 process");
          write (pfd[1], buf, strlen (buf));
          sleep (1);
        }
    }
}
