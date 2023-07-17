#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  for(int i=1;i<=9;i++)
  {
    for(int j=1;j<=9;j++) 
    {
      if(j==9)
      {
        printf("%d*%d=%d\n",j,i,j*i);
      }
       else
      {
        printf("%d*%d=%d ",j,i,j*i);
      }
    }
  }
  exit(0);
}
