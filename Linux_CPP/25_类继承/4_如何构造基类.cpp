#include <iostream>
using namespace std;

class A // 基类
{
public:
  int m_a;

private:
  int m_b;

public:
  A () : m_a (0), m_b (0) { cout << "调用了基类的默认构造函数A()" << endl; }
  A (int a, int b) : m_a (a), m_b (b)
  {
    cout << "调用了基类的构造函数A(int a, int b)" << endl;
  }
  A (const A &a) : m_a (a.m_a + 1), m_b (a.m_b + 1)
  {
    cout << "调用了基类的拷贝构造函数A(const A &a)" << endl;
  }
  void
  showA ()
  {
    cout << "m_a=" << m_a << ", m_b=" << m_b << endl;
  }
};

class B : public A
{
public:
  int m_c;
  // 如果派生类指名基类的构造函数则使用默认构造函数 A()
  B () : m_c (0) { cout << "调用了派生类的构造函数B()" << endl; }
  // 如果像这样指明基类的构造函数则使用那个对应的构造函数
  B (int a, int b, int c) : A (a, b), m_c (c) { ; }
  void
  showB ()
  {
    cout << "m_c= " << m_c << endl;
  }
};