#include <stdio.h>
#include <stdlib.h>



static int
fib(int n)
{
  if(n<1)
  {
    fprintf(stderr, "input err!\n");
    exit(-1);
  }
  else if(n == 1||n == 2)
  {
    return 1;
  }
  else
  return (fib(n-1)+fib(n-2));
}

int
main(void)
{
  int n;
  int ret;
  scanf("%d",&n);
  ret = fib(n);
  printf("fib[%d] = %d\n",n,ret);
  exit(0);
}
