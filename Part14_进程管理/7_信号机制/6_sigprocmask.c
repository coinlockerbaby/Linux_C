#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void
handler (int sig)
{
  printf ("I get sig = %d\n", sig);
}

int
main ()
{
  struct sigaction act;
  act.sa_handler = handler;
  sigemptyset (&act.sa_mask);
  act.sa_flags = 0;
  sigaction (SIGINT, &act, NULL);
  // 信号阻塞
  sigset_t set;                        // 定义信号集
  sigemptyset (&set);                  // 清空信号集
  sigaddset (&set, SIGINT);            // 添加信号到信号集
  sigprocmask (SIG_BLOCK, &set, NULL); // 把集合的信号屏蔽
  sleep (5);
  sigprocmask (SIG_UNBLOCK, &set, NULL);
  while (1)
    {
      sleep (1);
    }
}