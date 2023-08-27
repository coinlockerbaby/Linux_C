#include <stdio.h>

void
maopao (int *a, int len)
{
  for (int i = 0; i < len - 1; i++)
    {
      for (int j = 0; j < len - i - 1; j++)
        {
          if (a[j] > a[j + 1])
            {
              int tmp = a[j];
              a[j] = a[j + 1];
              a[j + 1] = tmp;
            }
        }
    }
  for (int i = 0; i < len; i++)
    printf ("%d ", a[i]);
  printf ("\n");
}

int
main ()
{
  int a[] = { 2, 3, 1, 5, 4, 8, 6, 7, 9 };
  maopao (a, sizeof (a) / sizeof (int));
}