// 多继承就是继承多个基类

#include <iostream>

using namespace std;

class A
{
public:
  int m_a = 10;
};

class B : virtual public A
{

};

class C : virtual public A
{

};
class D : public B, public C
{

};

auto
main()->int
{
  D d;
  cout << "B::m_a的地址是：" << &d.B::m_a << "，值是：" << d.B::m_a << endl;
  cout << "C::m_a的地址是：" << &d.C::m_a << "，值是：" << d.C::m_a << endl;
}