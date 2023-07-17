#include <stdio.h>
#include <stdlib.h>

#define KQ 950
#define WEIGHT 3.0e-23

static void func(void)
{
  float count;
  float sum;
  printf("请输入水夸脱数\n");
  scanf("%f",&count);
  if(count <=0)
  {
    fprintf(stderr,"input error!\n");
    exit(-1);
  }
  sum = count*KQ/WEIGHT;
  printf("sum = %e\n",sum);
  return ;
}


int main(void)
{
  func();
  exit(0);
}
