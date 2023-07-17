#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  for(int i=0;i<100/5;i++)
  {
    for(int j=0;j<100/3;j++)
    {
      int k = 100-(i+j);
      if(k%3==0 && (5*i+3*j+1*k/3)==100)
      {
        printf("%d %d %d\n",i,j,k);
      }
    }
  }
  exit(0);
}
