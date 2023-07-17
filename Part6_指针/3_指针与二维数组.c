#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int a[4][4] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
  // int *R = a;  // 这样是错误的 int *R 定义的是一个列移动的指针
  int *C = *a; // 列指针
  int (*b)[4] = a; // 数组指针定义  这个数组指针每次移动int[4]
  for(int i=0;i<4;i++)
  {
    for(int j=0;j<4;j++)
    {
      printf("%p -> %d\n",&a[i][j],a[i][j]);
    }
    printf("\n");
  }
  printf("行指针\n");
  printf("%p -> %d\n",a+1,*(*(a+1)));
  printf("列指针\n");
  printf("%p -> %d\n",C+4,*(C+4));
  printf("数组指针\n");
  printf("%p -> %d\n",b+1,*(*(b+1)));
  exit(0);
}
