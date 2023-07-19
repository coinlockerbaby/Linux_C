#include <stdio.h>
#include <stdlib.h>

static int
add(int a, int b)
{
  return a+b;
}


int
main(void)
{
  int a = 1,b = 2;
  int ret;
  int (*p)(int, int);
  p = add;
  ret = p(a,b);
  printf("%d\n",ret);
  exit(0);
}
