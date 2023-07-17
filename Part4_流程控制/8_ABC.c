#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int i;
  char j;
  for(i=0;i<6;i++)
  {
    for(j='A'+i;j<('A'+6);j++)
    {
      printf("%c",j);
    }
    printf("\n");
  }
  exit(0);
}
