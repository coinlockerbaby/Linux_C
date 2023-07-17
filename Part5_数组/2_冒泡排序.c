#include <stdio.h>
#include <stdlib.h>

#define maxlen 10

static void maopao(void)
{
  int arr[maxlen] = {1,4,6,13,456,12,13,131,54,12};
  for(int i=0;i<maxlen-1;i++)
  {
    for(int j = 0; j< maxlen-1-i; j++)
    {
      if(arr[j]>arr[j+1])
      {
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
  for(int i=0;i<maxlen;i++)
  {
    printf("%d ",arr[i]);
  }
  printf("\n");
}



int main(void)
{
  maopao();
  exit(0);
}
