#include<stdio.h>
#include<stdlib.h>

#define MAX_LEN   128

int main(void)
{
  char shuzu[MAX_LEN];
  gets(shuzu);
  int num = 0;
  int flag = 0;
  for(int i=0;shuzu[i]!='\0';i++)
  {
    if(shuzu[i] == ' ')
    {
      flag = 0;
    }
    else if (flag == 0) {
      flag = 1;
      num++;
    }
  }
  printf("there hava %d word\n",num);
  exit(0);
}
