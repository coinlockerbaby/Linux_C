// 如果把类的成员声明为静态的，就可以把它与类的对象独立开来（静态成员不属于对象）。
#include <iostream>
using namespace std;

class girl
{
public:
  girl (const string name, int age) : m_name (name)
  {
    m_age = age;
    cout << "调用构造函数" << endl;
  }
  void
  show () const
  {
    cout << "姓名: " << m_name << "\n年龄: " << m_age << endl;
  }

private:
  string m_name;
  static int m_age;
};

int girl::m_age = 12;

int
main ()
{
  girl g1 ("西施", 23);
  g1.show ();
}