#include <iostream>
using namespace std;

// 派生类可以通过继承基类的公有成员函数来访问基类的私有成员

class a
{
private:
  int m_a = 10;
  int m_b = 20;
public:
  void
  func()
  {
    cout << m_a << endl;
  }
};

class b :public a
{

};

auto
main()->int
{
  b B;
  B.func();
}