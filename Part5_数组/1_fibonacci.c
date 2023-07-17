// fibonacci 数列 逆序存放
#include <stdio.h>
#include <stdlib.h>

#define size  10

int fib[size] = {1,1};

static void fibonacci(void)
{
  for(int i=2;i<10;i++)
  {
    fib[i] = fib[i-1]+fib[i-2];
  }
}


static void antiorder(void)
{
  int i = 0; 
  int j = (sizeof(fib)/sizeof(fib[0]))-1;
  int temp;
  while(i<j)
  {
    temp = fib[i];
    fib[i] = fib[j];
    fib[j] = temp;
    i++;
    j--;
  }
}

int main(void)
{
  fibonacci();
  antiorder();
  for(int i=0;i<10;i++)
  {
    printf("fibonacci[%d] = %d\n",i,fib[i]);
  }
  exit(0);
}
