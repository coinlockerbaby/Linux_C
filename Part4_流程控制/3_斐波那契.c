#include<stdio.h>
#include<stdlib.h>

int main(void)
{
  int fibonacci2=0;
  int fibonacci1=1;
  int fibonacci =0;
  for(int i=0;i<40;i++) 
  {
    fibonacci = fibonacci1+fibonacci2;
    fibonacci2 = fibonacci1;
    fibonacci1 = fibonacci;
    printf("fibonacci[%d] = %d\n",i,fibonacci2);
  }
  exit(0);
}
