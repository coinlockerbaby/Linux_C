#include <stdio.h>
#include <stdlib.h>


static int
stagemulti(int n)
{
  if(n < 0)
  {
    fprintf(stderr,"input error\n");
    exit(1);
  }
  else if(n == 0)
  {
    return 1;
  }
  else
  {
    return n*stagemulti(n-1);
  }
}


int
main(void)
{
  int n;
  int ret;
  scanf("%d",&n);
  // 阶乘
  ret = stagemulti(n);
  printf("%d! = %d\n",n,ret);
  exit(0);
}
