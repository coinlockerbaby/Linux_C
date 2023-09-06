#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int *
thread_1 (void *arg)
{
  printf ("this is thread_1 pid = %d tid = %lu\n", (int)getpid (),
          pthread_self ());
  printf ("this is %d thread\n", (int)arg);
  pthread_exit (NULL);
  printf ("after pthread exit\n");
}

int
main ()
{
  pthread_t tid[5];
  int ret;
  int arg = 5;
  for (int i = 0; i < 5; i++)
    {
      ret = pthread_create (&tid[i], NULL, (void *)thread_1, (void *)i);
      printf ("this is main thread pid = %d tid = %lu\n", (int)getpid (),
              tid[i]);
    }
  sleep (1);
}