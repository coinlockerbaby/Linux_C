#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static void root(void)
{
  float a,b,c;
  float x1,x2;
  printf("please input a b c value\n");
  scanf("%f%f%f",&a,&b,&c);
  printf("a=%f,b=%f,c=%f\n",a,b,c);
  if((b*b-4*a*c)<=0)
  {
    fprintf(stderr,"input error!\n");
    exit(1);
  }
  x1 = (-b+sqrt(b*b-4*a*c))/2*a;
  x2 = (-b-sqrt(b*b-4*a*c))/2*a;
  printf("the value x1=%f x2=%f\n",x1,x2);
  exit(0);
}
int main(void)
{
  root();
  exit(0);
}
