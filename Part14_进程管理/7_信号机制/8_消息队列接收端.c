#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MSGLEN (sizeof (msgT) - sizeof (long))

typedef struct
{
  long msg_type;
  char buf[128];
} msgT;

int
main ()
{
  key_t key;
  int msgid;
  msgT msg;
  int ret;
  key = ftok ("test.txt", 1);
  if (key < 0)
    {
      perror ("ftok");
      exit (0);
    }
  if (msgid < 0)
    {
      perror ("msgget");
      exit (0);
    }
  msgid = msgget (key, IPC_CREAT | 0666);
  while (1)
    {
      ret = msgrcv (msgid, &msg, MSGLEN, 1, 0);
      if (ret < 0)
        {
          perror ("msgrcv");
          exit (0);
        }
      printf ("msg receive type = %ld buf = %s\n", msg.msg_type, msg.buf);
    }
}