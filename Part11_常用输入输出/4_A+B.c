#include <stdio.h>
int
main ()
{
  int a = 0, b = 0, sum = 0;
  while (scanf ("%d", &a) && (a != 0))
    {
      for (int i = 0; i < a; i++)
        {
          scanf ("%d", &b);
          sum += b;
        }
      printf ("%d\n", sum);
      sum = 0;
    }
}