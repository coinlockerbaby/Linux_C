#include <iostream>
using namespace std;

class girl
{
public:
  int m_bh;
  string m_name;
  int m_weight;
  girl ()
  {
    m_bh = 0;
    m_name.clear ();
    m_weight = 0;
  }
  void
  show ()
  {
    cout << "bh = " << m_bh << ", name = " << m_name
         << ", m_weight = " << m_weight << endl;
  }
  explicit girl (int i) // explicit 的作用是指定构造函数或转换函数 (C++11起)为显式, 即它不能用于隐式转换和复制初始化.
  // 在实际开发中，如果强调的是构造关闭自动类型转换比较合适
  {
    m_bh = i;
    m_name.clear ();
    m_weight = 0;
    cout << "调用了girl (int i)" << endl;
  }
  girl (double i)
  {
    m_bh = i;
    m_name.clear ();
    m_weight = 0;
    cout << "调用了girl (double i)" << endl;
  }
};

auto
main () -> int
{
  // girl g1 (8);        // 常规写法
  // girl g1 = girl (8); // 显式转换
  girl g1 = 8;        // 隐式转换
  // girl g1;            // 用默认构造函数创建
  // g1 = 8;             // 用gilr(8)创建临时对象再赋值给g
  g1.show ();
}