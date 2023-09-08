#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

pthread_mutex_t mutex1;
pthread_mutex_t mutex2;

void *
func (void *arg)
{
  pthread_detach (pthread_self ()); // detach线程,进程无需回收
  printf ("this is func1 thread\n");
  char str[] = "i write func1 line\n";
  while (1)
    {
      pthread_mutex_lock (&mutex1);
      printf ("%d i got lock 1\n", (int)arg);
      sleep (1);
      pthread_mutex_lock (&mutex2);
      printf ("%d i got 2 locks\n", (int)arg);
      pthread_mutex_unlock (&mutex2);
      pthread_mutex_unlock (&mutex1);
      usleep (1); // 一定要加个延时不然线程二无法入场
    }
}

void *
func2 (void *arg)
{
  pthread_detach (pthread_self ());
  printf ("this is fun2 thread\n");
  char str[] = "i write func2 line\n";
  int i = 0;
  while (1)
    {
      pthread_mutex_lock (&mutex2);
      printf ("%d i got lock 2\n", (int)arg);
      sleep (1);
      pthread_mutex_lock (&mutex1);
      printf ("%d i got 2 locks\n", (int)arg);
      pthread_mutex_unlock (&mutex1);
      pthread_mutex_unlock (&mutex2);
      usleep (1);
    }
}

int
main ()
{
  pthread_t thread1, thread2;
  // 动态初始化锁
  pthread_mutex_init (&mutex1, NULL);
  pthread_mutex_init (&mutex2, NULL);
  pthread_create (&thread1, NULL, func, 1);
  pthread_create (&thread2, NULL, func2, 2);
  while (1)
    {
      sleep (1);
    }
}