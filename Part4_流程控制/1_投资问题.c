#include <stdio.h>
#include <stdlib.h>



int main(void)
{
  float base=100; //本金
  float lixi1=0.1; //利息1
  float lixi2=0.05; //利息2
  float func1_money=100;
  float func2_money=100;
  int i = 0;
  for(i=1;func2_money<=func1_money;i++)
  {
    func1_money += base*lixi1;
    func2_money += func2_money*lixi2;
  }
  printf("when %d year \n func1_money = %f\n func2_money = %f\n",i,func1_money,func2_money);
}
