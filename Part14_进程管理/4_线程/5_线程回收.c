#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *
func (void *argv)
{
  printf ("this is child thread\n");
  sleep (1);
  pthread_exit ("thread return"); // 线程退出 返回返回值
}

int
main ()
{
  pthread_t tid[5];
  void *retv;
  for (int i = 0; i < 5; i++)
    {
      pthread_create (&tid[i], NULL, func, NULL);
    } 
  for (int i = 0; i < 5; i++)
    {
      pthread_join (tid[i], &retv);
      printf ("thread ret = %s\n", (char *)retv);
    }
  
  sleep (1);
}