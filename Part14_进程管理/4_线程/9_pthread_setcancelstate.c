#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *
func (void *argv)
{
  pthread_setcancelstate (PTHREAD_CANCEL_DISABLE, NULL);
  printf ("this is child thread\n");
  // while (1)
  {
    sleep (5);
    pthread_setcancelstate (PTHREAD_CANCEL_ENABLE, NULL);
  }
  while (1)
    {
      sleep (1);
    }
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
      sleep (5);
    }
}
