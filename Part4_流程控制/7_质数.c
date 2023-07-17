#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void)
{
  int i,j,mark;
  for(i=2;i<=1000;i++)
  {
    mark = 1;
    for(j=2;j<=sqrt(i);j++)
    {
      if(i%j==0)
      {
        mark = 0;
        break;
      }
    }
    if(mark)
    {
      printf("the prime is %d\n",i);
    }
  }
  exit(0);
}
