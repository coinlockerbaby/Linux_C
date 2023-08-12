// 链接：https://ac.nowcoder.com/acm/contest/5652/B
// 来源：牛客网

// 输入描述:
// 输入第一行包括一个数据组数t(1 <= t <= 100)
// 接下来每行包括两个正整数a,b(1 <= a, b <= 1000)
#include <stdio.h>
#include <stdlib.h>
int
main ()
{
  int a, b, c;
  scanf ("%d", &a);
  int e = a;
  int* d = malloc(a*sizeof(int));
  do
    {
      scanf ("%d %d", &b, &c);
      d[a] = b + c;
    }
  while (--a);
  do
    {
      printf ("%d\n", d[e]);
    }
  while (--e);
}

