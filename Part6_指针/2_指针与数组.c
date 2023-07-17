#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int a[3] = {1,2,3};
  int *p = a;

  int *b = (int [3]){1,2,3};
  
  for(int i=0;i<3;i++)
  {
    printf("%p -> %d\n",b+i,*(b+i));
  }
  exit(0);
}
