// 链接：https://ac.nowcoder.com/acm/contest/5652/C
// 来源：牛客网

// 输入描述:
// 输入包括两个正整数a,b(1 <= a, b <= 10^9),输入数据有多组, 如果输入为0
// 0则结束输入 输出描述: 输出a+b的结果
#include <stdio.h>

int
main ()
{
  int a, b;
  while (scanf ("%d %d", &a, &b) && (a != 0) && (b != 0))
    {
      printf ("%d\n", a + b);
    }
}