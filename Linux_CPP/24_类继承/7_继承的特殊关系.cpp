#include <iostream>
using namespace std;

class A
{
public:
  int m_a = 0;

private:
  int m_b = 0;

public:
  void
  show ()
  {
    cout << "A::show() m_a= " << m_a << ", m_b= " << m_b << endl;
  }
  void
  setb (int b)
  {
    m_b = b;
  }
};

class B : public A
{
public:
  int m_c = 0;
  void
  show ()
  {
    cout << "B::show() m_a= " << m_a << ", m_c= " << m_c << endl;
  }
};


// 可以把派生类赋值给基类对象，但是会舍弃非基类的成员
// 基类指针可以指向派生类
int
main ()
{
  A a;
  B b;
  b.m_a = 10;   // A::m_a = 10
  b.setb (20);  // A::m_b = 20
  b.m_c = 30;   // B::m_C = 30

  a.show();
  a = b;
  a.show();
}