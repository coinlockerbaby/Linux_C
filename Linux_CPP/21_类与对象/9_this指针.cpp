//this指针存放了对象的地址，它被作为隐藏参数传递给了成员函数，指向调用成员函数的对象（调用者对象）。
#include <iostream>
#include <stdlib.h>

using namespace std;

class girl
{
public:
  string m_name;
  int m_age;
  girl (const string name, int age)
  {
    m_name = name;
    m_age = age;
  }
  void
  show () const
  {
    cout << "我是: " << m_name << ", 最年轻的超女" << endl;
  }
  const girl&
  pk (const girl& g) const
  {
    if (m_age < g.m_age)
      return *this;
    else
      return g;
  }
};

int
main ()
{
  girl girl1 ("girl1", 14);
  girl girl2 ("girl2", 15);
  const girl girl3 = girl1.pk(girl2);
  girl3.show();
  
}