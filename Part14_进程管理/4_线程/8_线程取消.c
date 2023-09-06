#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *
func (void *argv)
{
  printf ("this is child thread\n");
  while (1)
    {
      //sleep (5);
      pthread_testcancel();
    }
  pthread_exit ("thread return");
}

int
main ()
{
  pthread_t tid;
  void *retv;
  pthread_create (&tid, NULL, func, NULL);
  sleep (5);
  pthread_cancel (tid);
  pthread_join (tid, &retv);
  // printf ("thread ret %s\n", (char*)retv);
  while (1)
    {
      sleep (5);
    }
}
