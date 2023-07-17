#include<stdio.h>
#include<stdlib.h>

int main(void)
{
  int input_num;
  int odd_sum=0;
  int even_sum=0;
  int odd_cnt=0,even_cnt=0;
  while(1)
  {
    printf("input a int value\n");
    scanf("%d", &input_num);
    if(input_num == 0)
    {
      fprintf(stderr, "you input 0\n");
      break;
    }
    if(input_num%2 == 0)
    {
      even_sum+=input_num;
      even_cnt++;
    }
    else 
    {
      odd_sum+=input_num;
      odd_cnt++;
    }
  }
  printf(" even_cnt=%d\n even_sum=%d\n odd_cnt=%d\n odd_sum=%d\n",even_cnt,even_sum,odd_cnt,odd_sum);
  exit(0);
}
