// 多继承就是继承多个基类

#include <iostream>

using namespace std;

class A1
{
public:
  int m_a = 10;
};

class A2
{
public:
  int m_b = 20;
};

class B : public A1, public A2
{
public:
  int m_c = 30;
};


auto
main()->int
{
  B b;
  cout << "A1::m_a = " << b.A1::m_a << ", A2::m_b = " << b.A2::m_b << endl;
}