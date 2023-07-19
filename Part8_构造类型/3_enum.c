#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum day { MON, TUS, THR, WES };

int
main(void)
{
  enum day a = MON;
  printf("%d", a);
  exit(0);
}
