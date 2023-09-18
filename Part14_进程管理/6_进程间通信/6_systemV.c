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
  char *buf;
  // 根据文件路径和整数标识符转换为key值
  key = ftok ("ftok.txt", 1);
  if (key < 0)
    {
      perror ("ftok");
      exit (-1);
    }
  printf ("key = %x\n", key);
  // 创建共享内存
  shmid = shmget (key, 512, IPC_CREAT | 0666);
  if (shmid < 0)
    {
      perror ("shmget");
      exit (-1);
    }
  printf ("shmid = %d\n", shmid);
  // 映射共享内存
  buf = shmat (shmid, buf, 0);
  if (buf < 0)
    {
      perror ("shmat");
    }
  memcpy (buf, "hello world", 12);
  printf ("buf = %s\n", buf);
}