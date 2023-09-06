#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *
func (void *argv)
{
  printf ("this is child thread\n");
  sleep (5);
  pthread_exit ("thread return");
}

int
main ()
{
  pthread_t tid[5];
  pthread_attr_t attr;
  pthread_attr_init (&attr);
  pthread_attr_setdetachstate (&attr, PTHREAD_CREATE_DETACHED);
  for (int i = 0; i < 5; i++)
    {
      pthread_create (&tid[i], &attr, func, NULL);
    }
  while (1)
    {
      sleep (1);
    }
}