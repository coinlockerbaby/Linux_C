#include <iostream>
using namespace std;

class A //  基类
{
public:
  int m_a = 10;
  void
  func ()
  {
    cout << "调用了A的func()函数" << endl;
  }
};

class B : public A // 子类
{
public:
  int m_a = 20;
  void
  func ()
  {
    cout << "调用了B的func()函数" << endl;
  }
};

class C : public B // 孙类
{
public:
  int m_a = 30;
  void
  func ()
  {
    cout << "调用了C的func()函数" << endl;
  }
};
// 当存在继承关系时，基类的作用域嵌套在派生类的作用域中。如果成员在派生类的作用域中已经找到，
// 就不会在基类作用域中继续查找；如果没有找到，则继续在基类作用域中查找。
int
main ()
{
  C c; // 创建孙类对象
  cout << "C::m_a的值是: " << c.C::m_a << endl;
  cout << "B::m_a的值是: " << c.B::m_a << endl;
  cout << "A::m_a的值是: " << c.B::A::m_a << endl;
  c.B::A::func();
  c.B::func();
  c.C::func();
}