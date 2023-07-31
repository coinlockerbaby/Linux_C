// 构造函数：在创建对象时，自动的进行初始化工作。
// 析构函数：在销毁对象前，自动的完成清理工作。
// 1）构造函数
// 语法：类名(){......}
// 访问权限必须是public。
// 函数名必须与类名相同。
// 没有返回值，不写void。
// 可以有参数，可以重载，可以有默认参数。
// 创建对象时只会自动调用一次，不能手工调用。
// 2）析构函数
// 语法：~类名(){......}
// 访问权限必须是public。
// 函数名必须在类名前加~。
// 没有返回值，也不写void。
// 没有参数，不能重载。
// 销毁对象前只会自动调用一次，但是可以手工调用。
#include <iostream>
using namespace std;

class girl
{
public:
  string m_name; // 姓名属性
  int m_age;     // 年龄属性
  // 构造函数
  girl ()
  {
    m_name.clear ();
    m_age = 0;
    cout << "调用了构造函数" << endl;
  }
  // 带型参的构造函数
  girl (string name, int age)
  {
    m_name = name;
    m_age = age;
    cout << "调用了带参数的构造函数" << endl;
  }
  // 析构函数
  ~girl () { cout << "调用了析构函数" << endl; }

  void
  girl_init (string name, int age)
  {
    m_name = name;
    m_age = age;
  }
  void
  show (void)
  {
    cout << "姓名: " << m_name << "\n年龄: " << m_age << endl;
  }
};

auto
main () -> int
{
  // girl girls();
  // girls.show();
  girl girls ("lihua", 14);
  girls.show ();
}