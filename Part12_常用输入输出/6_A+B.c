#include <stdio.h>

int
main ()
{
  int a, num, sum = 0;
  while (scanf ("%d", &a) == 1)
    {

      sum = 0;
      while (a--)
        {
          scanf ("%d", &num);
          sum += num;
        }
      printf ("%d\n", sum);
    }
}