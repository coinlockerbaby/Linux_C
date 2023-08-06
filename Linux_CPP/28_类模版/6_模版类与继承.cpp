#include <iostream>
using namespace std;

class AA
{
public:
  int m_a;
  AA(int a) : m_a(a)
  {
    cout << "调用了AA的构造函数" << endl;
  }
  void
  func1() const
  {
    cout << "调用了func1()函数 m_a=" << m_a << endl; 
  }
};

template <class T1, class T2>
class BB : public AA
{
public:
  T1 m_x;
  T2 m_y;
  BB (const T1 x, const T2 y, int a) : AA(a), m_x(x), m_y(y)
  {
    cout << "调用了BB的构造函数" << endl;
  }
  void
  func2() const
  {
    cout <<  "调用了func2()函数 m_x="<< m_x << ",m_y=" << m_y << endl;
  }
};
int
main()
{
  BB <int, int> bb(10,20,3);
  bb.AA::func1();
  bb.func2();
}