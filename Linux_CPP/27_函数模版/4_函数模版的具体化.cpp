// 可以提供一个具体化的函数定义，当编译器找到与函数调用匹配的具体化定义时，将使用该定义，不再寻找模板。
//  具体化（特例化、特化）的语法：
//  template<> void 函数模板名<数据类型>(参数列表)
//  template<> void 函数模板名 (参数列表)
//  {
//  	// 函数体。
//  }
// 编译器使用各种函数的规则：
// 1）具体化优先于常规模板，普通函数优先于具体化和常规模板。
// 2）如果希望使用函数模板，可以用空模板参数强制使用函数模板。
// 3）如果函数模板能产生更好的匹配，将优先于普通函数。

#include <iostream>
using namespace std;

class CGirl
{
public:
  int m_bh;
  string m_name;
  int m_rank;
};

// 普通函数
void
Swap (int &a, int &b)
{
  int tmp = a;
  a = b;
  b = tmp;
  cout << "使用了普通函数" << endl;
}

// 普通模版
template <typename T>
void
Swap (T &a, T &b)
{
  T tmp;
  tmp = a;
  a = b;
  b = tmp;
  cout << "使用了普通函数模版" << endl;
}

// 模版具体化
template <>
void
Swap (int &a, int &b)
{
  int tmp = a;
  a = b;
  b = tmp;
  cout << "使用类函数模版具体化" << endl;
}

// 模版具体化
template <>
void
Swap (CGirl &a, CGirl &b)
{
  int tmp;
  tmp = a.m_rank;
  a.m_rank = b.m_rank;
  b.m_rank = tmp;
  cout << "使用了具体化函数" << endl;
}

int
main ()
{
  int a = 10;
  int b = 20;
  Swap(a,b);
  cout << "a=" << a << ", b=" << b << endl;
}