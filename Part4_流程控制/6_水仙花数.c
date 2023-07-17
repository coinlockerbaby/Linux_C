#include <stdio.h>
#include <stdlib.h>




int main(void)
{
  int i;
  for(i = 100;i<1000;i++)
  {
    // 百位
    int baiwei;
    baiwei = i/100;
    // 十位
    int shiwei;
    shiwei = (i%100)/10;
    // 个位
    int gewei;
    gewei = i%10;

    if(i == baiwei*baiwei*baiwei+shiwei*shiwei*shiwei+gewei*gewei*gewei)
    {
      printf("the flower number is %d\n",i);
    }
  }
  exit(0);
}
