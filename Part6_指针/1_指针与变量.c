#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int i = 1;
  int *p;
  p = &i;
  printf("sizeof(i) = %d\n",sizeof(i));
  printf("sizeof(p) = %d\n",sizeof(p));
  printf("i = %d\n", i);
  printf("&i = %p\n", &i);
  printf("p = %p\n",p);
  printf("&p = %p\n",&p);
  printf("*p = %d\n", *p);
  exit(0);
}
