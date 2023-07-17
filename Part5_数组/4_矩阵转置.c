#include <stdio.h>
#include <stdlib.h>

#define M 2
#define N 2


static void matrix_t(void)
{
  int a[M][N] = {1,2,3,4};
  int b[M][N]; 
  for(int i=0;i<2;i++)
  {
    for(int j=0;j<2;j++)
    {
      printf("%d ",a[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  for(int i=0;i<2;i++)
  {
    for(int j=0;j<2;j++)
    {
      b[j][i] = a[i][j];
    }
  }
  for(int i=0;i<2;i++)
  {
    for(int j=0;j<2;j++)
    {
      printf("%d ",b[i][j]);
    }
    printf("\n");
  }
}

int main(void)
{
  matrix_t();
  exit(0);
}
