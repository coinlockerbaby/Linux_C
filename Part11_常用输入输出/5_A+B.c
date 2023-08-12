#include <stdio.h>

int
main()
{
  int a, b, num, sum = 0;
  scanf ("%d", &a);
  while (a--)
    {
      sum = 0;
      scanf ("%d", &b);
      while (b--)
        {
          scanf ("%d", &num);
          sum += num;
        }
      printf ("%d\n", sum);
    }
}