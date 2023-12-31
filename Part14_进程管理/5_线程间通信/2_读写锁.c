#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

FILE *fp;
pthread_mutex_t mutex1;
pthread_rwlock_t rwlock;

void *
read_func (void *arg)
{
  pthread_detach (pthread_self ());
  printf ("read thread\n");
  char buf[32] = { 0 };
  pthread_rwlock_rdlock (&rwlock);
  while (1)
    {
      while (fgets (buf, 32, fp))
        {
          printf ("%d read=%s\n", (int)arg, buf);
          usleep (1000);
        }
      pthread_rwlock_unlock (&rwlock);
    }
  usleep (1);
}

void *
func (void *arg)
{
  pthread_detach (pthread_self ()); // detach线程,进程无需回收
  printf ("this is func1 thread\n");
  char str[] = "i write func1 line\n";
  while (1)
    {
      pthread_rwlock_wrlock (&rwlock);
      for (int i = 0; i < strlen (str); i++)
        {
          fputc (str[i], fp);
          usleep (1);
        }
      pthread_rwlock_unlock (&rwlock);
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
      pthread_rwlock_wrlock (&rwlock);
      for (int i = 0; i < strlen (str); i++)
        {
          fputc (str[i], fp);
          usleep (1);
        }
      pthread_rwlock_unlock (&rwlock);
      usleep (1);
    }
}

int
main ()
{
  pthread_t thread1, thread2, thread3, thread4;
  // 动态初始化锁
  pthread_rwlock_init (&rwlock, NULL);
  fp = fopen ("1.txt", "a+");
  if (fp == NULL)
    {
      perror ("fopen");
      return 0;
    }
  pthread_create (&thread3, NULL, read_func, 1);
  pthread_create (&thread4, NULL, read_func, 2);
  sleep (1);
  pthread_create (&thread1, NULL, func, NULL);
  pthread_create (&thread2, NULL, func2, NULL);
  while (1)
    {
      sleep (1);
    }
}