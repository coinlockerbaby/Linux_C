#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int *
thread_1 (void *arg)
{
  printf ("this is thread_1 pid = %d tid = %lu\n", (int)getpid (),
          pthread_self ());
  printf ("input arg = %d\n", *(int *)arg);
  pthread_exit (NULL);
  printf ("after pthread exit\n");
}

int
main ()
{
  pthread_t tid;
  int ret;
  int arg = 5;
  ret = pthread_create (&tid, NULL, (void *)thread_1, (void *)&arg);
  printf ("this is main thread pid = %d tid = %lu\n", (int)getpid (), tid);
  sleep (2);
}