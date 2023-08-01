//如果要访问类的私有成员变量，调用类的公有成员函数是唯一的办法，而类的私有成员函数则无法访问。
// 友元提供了另一访问类的私有成员的方案。友元有三种：
// 友元全局函数。
//在友元全局函数中，可以访问另一个类的所有成员。
// 友元类。
//在友元类所有成员函数中，都可以访问另一个类的所有成员。
// 友元成员函数。
#include <iostream>
using namespace std;

class girl
{
  friend void func(); // 友元全局函数
  friend class boy;   // 友元类
public:
  string m_name;
  girl()
  {
    m_name = "西施";
    m_xw = 87;
  }
  void
  showname()
  {
    cout << "姓名: "<< m_name <<endl;
  }
private:
  int m_xw; //胸围
  void
  showxw()
  {
    cout << "胸围: " <<m_xw<<endl;
  }
};

class boy
{
public:
  void func2(const girl& g)
    {
      cout << "我的女朋友是:"<< g.m_name<< " 胸围是: "<<g.m_xw <<endl;
    }
};

void
func(void)
{
  girl g1;
  g1.showname();
  g1.showxw();
}

int
main()
{
  girl girl1;
  boy boy1;
  boy1.func2(girl1);
}