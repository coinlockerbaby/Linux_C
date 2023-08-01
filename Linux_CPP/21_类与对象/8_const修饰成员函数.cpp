//在类的成员函数后面加const关键字，表示在成员函数中保证不会修改调用对象的成员变量。
// 注意：
// 1）mutable可以突破const的限制，被mutable修饰的成员变量，将永远处于可变的状态，在const修饰的函数中，mutable成员也可以被修改。
// 2）非const成员函数可以调用const成员函数和非const成员函数。
// 3）const成员函数不能调用非const成员函数。
// 4）非const对象可以调用const修饰的成员函数和非const修饰的成员函数。
// 5）const对象只能调用const修饰的成员函数，不能调用非cosnt修饰的成员函数。
// 6) 不能给构造函数和析构函数加const
#include <iostream>

using namespace std;

class girl
{
public:
  string m_name;
  int m_age;
  girl (string name, int age)
  {
    m_name = name;
    m_age = age;
  }
  void
  show () const // 表示不会修改对象的成员变量
  {
    cout << "姓名: " << m_name << "\n年龄: " << m_age << endl;
  }
};

int
main ()
{
  girl girls("王者",12);
  girls.show();

}