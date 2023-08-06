// 函数模板是通用的函数描述，使用任意类型（泛型）来描述函数。
#include <iostream>
using namespace std;

// 创建一个函数模版
template <typename T>
void
Swap (T &a, T &b)
{
  T temp;
  temp = a;
  a = b;
  b = temp;
}

int
main ()
{
  int a = 1, b = 3;
  Swap(a,b);
  cout << "a=" << a << ", b=" << b << endl;
}