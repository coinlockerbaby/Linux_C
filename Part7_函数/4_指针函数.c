#include <stdio.h>
#include <stdlib.h>

#define M 3
#define N 4


static int *
find_num(int (*p)[N], int num)
{
  if(num > M-1) // 只有012行
  {
    fprintf(stderr, "%input error!\n");
    exit(1);
  }
  else
  return *(p+num); // 解引用成列指针
}


int
main(void)
{
  int i,j;
  int a[M][N] = {1,2,3,4,5,6,7,8,9,10,11,12};
  int num = 1;
  int *res = NULL; 
  res = find_num(a,num);
  for (int i = 0; i < N; i++)
  {
    printf("%d ",*(res+i));
  }
  printf("\n");
  exit(0);
}
