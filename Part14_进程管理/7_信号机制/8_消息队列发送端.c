#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

typedef struct
{
  long msg_type;
  char buf[128];
} msgT;

#define MSGLEN (sizeof (msgT) - sizeof (long))

int
main ()
{
  key_t key;
  int msgque_id;
  msgT msg;
  msg.msg_type = 1;
  strcpy (msg.buf, "this msg type 1");

  key = ftok ("test.txt", 1);
  if (key < 0)
    {
      perror ("ftok");
      exit (0);
    }
  msgque_id = msgget (key, IPC_CREAT | 0666);
  if (msgque_id < 0)
    {
      perror ("msgget");
      exit (0);
    }
  if (msgsnd (msgque_id, &msg, 128, 0) < 0)
    {
      perror ("msgsnd");
      exit (0);
    }
}
