#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void
cleanup (void *argv)
{
  printf ("cleanup.arg=%s\n", (char *)argv);
}

void *
func (void *argv)
{
  printf ("this is child thread\n");
  pthread_cleanup_push (cleanup, "hello");
  while (1)
    {
      sleep (1);
    }
  pthread_cleanup_pop (0);
}

int
main ()
{
  pthread_t tid;
  void *retv;
  pthread_create (&tid, NULL, func, NULL);
  sleep (2);
  pthread_cancel (tid);
  while (1)
    {
      sleep (1);
    }
}