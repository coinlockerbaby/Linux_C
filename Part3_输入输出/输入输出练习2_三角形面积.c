#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static void area(void)
{
  float a,b,c;
  float s, area;
  printf("please input the abc value\n");
  scanf("%f%f%f",&a,&b,&c);
  printf("a=%f b=%f c=%f\n",a,b,c);
  if(a+b<=c||b+c<=a||a+c<=b)
  {
    fprintf(stderr,"input error!\n");
    exit(-1);
  }
  s = (1.0/2)*(a+b+c);
  area = sqrt(s*(s-a)*(s-b)*(s-c));
  printf("the s value = %f\n", area);
}
int main(void)
{
  area();
  exit(0);
}
