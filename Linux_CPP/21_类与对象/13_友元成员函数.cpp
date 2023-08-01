// 在友元成员函数中，可以访问另一个类的所有成员。
// 如果要把男朋友类CBoy的某成员函数声明为超女类CGirl的友元，声明和定义的顺序如下：
// class CGirl;            // 前置声明。
// class CBoy { ...... };      // CBoy的定义。
// class CGirl { ...... };      // CGirl的定义。
#include <iostream>
using namespace std;

class girl;
class boy
{
public:
  void show (const girl &g1);
};


class girl
{
  friend void boy::show (const girl &g1);

public:
  string m_name;
  girl (string name, int age) : m_name (name), m_age (age) { ; }

private:
  int m_age;
  void
  show (void)
  {
    cout << "姓名: " << m_name << "年龄: " << m_age;
  }
};

void
boy::show (const girl &g1)
{
  cout << "女友年龄: " << g1.m_age << endl;
}

int
main()
{
  girl g1("小明", 110);
  boy b1;
  b1.show(g1);
}