#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 10


static void xuanze(void)
{
  int arr[MAX_LEN] = {23,45,90,76,13,55,76,45,3,8};
  for(int i=0;i<MAX_LEN-1;i++)
  {
    int min = i; // 最小数值的下标
    for(int j=i+1;j<MAX_LEN;j++)
    {
      if(arr[min] > arr[j])
      {
        min = j;
      }
    }
      int temp = arr[i];
      arr[i] = arr[min];
      arr[min] = temp;
  }
  for(int i=0;i<MAX_LEN;i++)
  {
    printf("%d ",arr[i]);
  }
  printf("\n");
}

int main(void)
{
  xuanze();
  exit(0);
}
