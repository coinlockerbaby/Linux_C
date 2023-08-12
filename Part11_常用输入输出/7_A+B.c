#include <stdio.h>

int
main ()
{
  int num, sum = 0;
  while (scanf ("%d", &num) != EOF)
    {
      sum += num;
      if (getchar () == '\n')
        {
          printf ("%d\n", sum);
          sum = 0;
        }
    }
}