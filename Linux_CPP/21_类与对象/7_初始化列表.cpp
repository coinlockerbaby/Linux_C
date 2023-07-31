#include <iostream>

using namespace std;

class girl
{
  string m_name;
  int m_age;

public:
  girl ():m_name("原神"),m_age(12)  // 初始化列表
  { cout << "调用构造函数" << endl; }
  girl (string name, int age)
  {
    m_name = name;
    m_age = age;
    cout << "调用了带参数的重载构造函数" << endl;
  }
  void
  show ()
  {
    cout << "姓名: " << m_name << "\n年龄: " << m_age << endl;
  }
};

int
main ()
{
  girl girls;
  girls.show ();
}