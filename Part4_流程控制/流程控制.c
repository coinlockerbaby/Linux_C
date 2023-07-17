#include <stdio.h>
#include <stdlib.h>

static void runnian(void)
{
  int year;
  printf("please input year\n");
  scanf("%d",&year);
  if((year % 4 == 0) && (year % 100 != 0) || (year %400 == 0))
  {
    printf("%d is leap year\n",year);
    exit(0);
  }
  else 
  {
    printf("%d not leap year\n", year);
    exit(0);
  }
}
int main(void)
{
  runnian();
  exit(0);
}
