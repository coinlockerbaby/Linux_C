#include <fcntl.h>
#include <pthread.h>
#include <semaphore.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

// 用于删除/dev/shm里面的信号量文件
void
delsemfile (int sig)
{
  sem_unlink ("mysem_w");
  exit (0);
}

int
main ()
{
  key_t key;
  int shmid;
  void *shmaddr;
  sem_t *sem_r, *sem_w; // 读信号量和写信号量

  key = ftok (".", 1);
  if (key < 0)
    {
      perror ("ftok");
      exit (0);
    }
  shmid = shmget (key, 128, IPC_CREAT | 0666);
  if (shmid < 0)
    {
      perror ("shmget");
      exit (0);
    }
  shmaddr = shmat (shmid, NULL, 0);
  sem_r = sem_open ("mysem_r", O_CREAT | O_RDWR, 0666, 0);
  sem_w = sem_open ("mysem_w", O_CREAT | O_RDWR, 0666, 1);
  struct sigaction act;
  act.sa_handler = delsemfile;
  act.sa_flags = 0;
  sigemptyset (&act.sa_mask);
  sigaction (SIGINT, &act, NULL);
  while (1)
    {
      sem_wait (sem_w); // 写信号-1
      printf (">");
      fgets (shmaddr, 128, stdin);
      sem_post (sem_r); // 读信号+1
    }
}