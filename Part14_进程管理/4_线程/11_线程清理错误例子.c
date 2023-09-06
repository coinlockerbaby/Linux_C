#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void
cleanup (void *argv)
{
  printf ("cleanup.argv = %s\n", (char *)argv);
}

void *
func (void *argv)
{
  printf ("this is child thread\n");

  pthread_cleanup_push (cleanup, "helloworld");
  pthread_exit ("pthread return");
  pthread_cleanup_pop (0);
}

int
main ()
{
  pthread_t tid;
  pthread_create (&tid, NULL, func, NULL);
  sleep (2); // 防止一创建线程就被取消
  // pthread_cancel (tid);
  while (1)
    {
      sleep (1);
    }
}