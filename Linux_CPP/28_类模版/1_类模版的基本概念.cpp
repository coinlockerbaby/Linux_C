// 类模板是通用类的描述，使用任意类型（泛型）来描述类的定义。
// 使用类模板的时候，指定具体的数据类型，让编译器生成该类型的类定义。
// 语法：
// template <class T>
// class 类模板名
// {
// 	类的定义;
// };
// 函数模板建议用typename描述通用数据类型，类模板建议用class。

// 1）在创建对象的时候，必须指明具体的数据类型。
// 2）使用类模板时，数据类型必须适应类模板中的代码。
// 3）类模板可以为通用数据类型指定缺省的数据类型（C++11标准的函数模板也可以）。
// 4）模板类的成员函数可以在类外实现。
// 5）可以用new创建模板类对象。
// 6）在程序中，模板类的成员函数使用了才会创建。
#include <iostream>
using namespace std;

template <class T1, class T2 = int> class AA
{
public:
  T1 m_a; // 通用类型用于成员变量
  T2 m_b;
  AA () {}
  // 通用类型用于成员函数的参数
  AA (T1 a, T2 b) : m_a (a), m_b (b) {}
  // 通用类型用于成员函数的返回值
  T1
  geta ()
  {
    T1 a = 2; // 通用类型用于成员函数的代码中
    return m_a + a;
  }
  T2 getb ();
};
template <class T1, class T2>
T2
AA<T1, T2>::getb ()
{
  T2 b = 1;
  return m_a + b;
}

auto
main () -> int
{
  AA<int, double> *a = new AA<int, double>;
  a->m_a = 20, a->m_b = 30;
  cout << "a.geta()=" << a->geta () << endl;
  cout << "a.getb()=" << a->getb () << endl;
  delete a;
}