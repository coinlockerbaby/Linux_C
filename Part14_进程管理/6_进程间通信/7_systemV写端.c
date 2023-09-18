#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>

int
main ()
{
  key_t key;
  int shmid;
  void *buf;
  key = ftok ("ftok.txt", 1);
  if (key < 0)
    {
      perror ("ftok");
    }
  shmid = shmget (key, 512, IPC_CREAT | 0666); // 读端无需创建
  if (shmid < 0)
    {
      perror ("shmget");
    }
  buf = shmat (shmid, NULL, 0);
  if (buf < 0)
    {
      perror ("shmat");
    }
  memcpy (buf, "hello world", 12);
}