#include <stdio.h>
#include <stdlib.h>


static void 
swap(int *i, int *j)
{
  int temp;
  temp = *i;
  *i = *j;
  *j = temp;
}

int 
main(void)
{
  int i=3,j=5;
  swap(&i,&j);
  printf("i=%d j=%d\n",i,j);
  exit(0);
}
