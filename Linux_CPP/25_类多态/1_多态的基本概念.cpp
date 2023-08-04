// 如果基类的成员函数是虚函数那么用基类指针指向派生类后，调用的成员函数是基类的
// 当基类的成员函数用virtual修饰的时候调用的成员函数是派生类的
// 这就是多态

#include <iostream>
using namespace std;

class CALLComer
{
public:
  int m_bh = 0;
  virtual void
  show()
  {
    cout << "CALLComers::show(): 我是" << m_bh << "号" << endl;
  }
};

class girl : public CALLComer
{
public:
  int m_age = 0;
  void
  show()
  {
    cout << "girl::show(): 我是" << m_bh << "号" << m_age << "岁" << endl;
  }
};

int
main()
{
  girl g;
  g.m_bh = 8;
  g.m_age = 23;
  g.show();
  CALLComer *pa = &g;
  pa -> show();
}