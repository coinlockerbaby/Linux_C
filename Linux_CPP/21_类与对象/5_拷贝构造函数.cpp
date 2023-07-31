// 用一个已存在的对象创建新的对象，不会调用（普通）构造函数，而是调用拷贝构造函数。
// 如果类中没有定义拷贝构造函数，编译器将提供一个拷贝构造函数，它的功能是把已存在对象的成员变量赋值给新对象的成员变量。
// 用一个已存在的对象创建新的对象语法：
// 类名 新对象名(已存在的对象名);
// 类名 新对象名=已存在的对象名;
// 拷贝构造函数的语法：
// 类名(const 类名& 对象名){......}
#include <iostream>

using namespace std;

class girl
{
public:
  string m_name;
  int m_age;
  // 构造函数
  girl (string name, int age)
  {
    m_name = name;
    m_age = age;
    cout << "调用了构造函数"<<endl;
  }
  // 析构函数
  ~girl () { cout << "调用了析构函数" << endl; }
  // 拷贝构造函数
  // 我这边的拷贝构造函数的name是传入类的成员的"漂亮的"+name，年龄为0
  girl(const girl& old)
  {
    m_name = "漂亮的"+old.m_name;
    m_age  = 0;
    cout << "调用了拷贝构造函数" << endl;
  }
  void
  show ()
  {
    cout << "name= " << m_name << "\nage= " << m_age << endl;
  }
};
int
main ()
{
  girl girls("lihua",15);
  girl girls2(girls); // 通过编译器提供的拷贝构造函数将girls的成员变量拷贝到girls2类中
  girls2.show();
}