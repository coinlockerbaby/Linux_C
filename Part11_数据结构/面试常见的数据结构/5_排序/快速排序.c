#include <stdio.h>

int
partion (int *k, int low, int high)
{
  int tmp = k[low];
  while (low < high)
    {
      while ((low < high) && (tmp <= k[high]))
        high--;
      k[low] = k[high];
      while ((low < high) && (tmp >= k[low]))
        low++;
      k[high] = k[low];
    }
  k[low] = tmp;
  return low;
}
int
quick_sort (int *k, int low, int high)
{
  int t; //  基准点位置
  if (k == NULL)
    return -1;
  if (low >= high) // 递归结束条件
    return 0;

  t = partion (k, low, high);
  quick_sort (k, low, t - 1);
  quick_sort (k, t + 1, high);
}

int
main ()
{
  int k[] = { 50, 36, 66, 76, 36, 12, 25, 92 };
  quick_sort (k, 0, sizeof (k) / sizeof (int) - 1);
  for (int i = 0; i < sizeof (k) / sizeof (int); i++)
    printf ("%d ", k[i]);
}