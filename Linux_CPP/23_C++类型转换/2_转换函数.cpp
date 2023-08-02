// 构造函数只用于从某类型转到类类型的转换，如果要进行相反的转换，可以使用特殊的运算符函数----转换函数
// 实际项目中我们一般不会使用重载的方式，而是定义一个普通成员函数来帮助转换
#include <iostream>
using namespace std;

class girl
{
public:
  int m_bh;
  string m_name;
  double m_weight;

  girl () : m_bh (8), m_name ("西施"), m_weight (50.7) { ; }

  operator int () { return m_bh; }
  operator string () { return m_name; }
  operator double () { return m_weight; }
  int to_int () { return m_bh; }
};

auto
main () -> int
{
  girl g1;
  // int a = g1;
  int a = g1.to_int();
  cout << "a的值是: " << a << endl;
  string b = g1;
  cout << "b的值是: " << b << endl;
  double c = g1;
  cout << "c的值是: " << c << endl;
}