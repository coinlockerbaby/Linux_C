#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *
testThread (void *arg)
{
  char *threadName = (char*)arg;
  printf ("Current running threadName = %s\n", threadName);
  printf ("aaaaa\n");
  printf ("bbbbb\n");
  pthread_exit (0);
}


int
main ()
{
  pthread_t tid1, tid2;
  void *retv;
  pthread_create (&tid1, NULL, testThread, "thread1");
  pthread_create (&tid2, NULL, testThread, "thread2");
  // 回收线程
  pthread_join (tid1, NULL);
  pthread_join (tid2, NULL);
}