//如果派生类中的成员（包括成员变量和成员函数）和基类中的成员重名，通过派生类对象或者在派生类的成员函数中使用该成员时，将使用派生类新增的成员，而不是基类的。
//注意：基类的成员函数和派生类的成员函数不会构成重载，如果派生类有同名函数，那么就会遮蔽基类中的所有同名函数。
#include <iostream>
using namespace std;

class A
{
public:
  int m_a = 30;
  void
  func ()
  {
    cout << "调用了A的func()函数" << endl;
  }
};

class B : public A
{
public:
  int m_a = 80;
  void
  func ()
  {
    cout << "调用了B的func()函数" << endl;
  }
};

auto
main () -> int
{
  B b;
  cout << "m_a的值是: " << b.m_a << endl;
  b.func();
}