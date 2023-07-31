// 对面向对象编程来说，一切都是对象，对象用类来描述
// 类把对象的数据和操作方法作为一个整体考虑
#include <iostream>
#include <stdlib.h>

using namespace std;

// 结构体
// struct st_girl
// {
//   string name;
//   int age;
//   void
//   show ()
//   {
//     cout << "姓名: " << name << "\n年龄: " << age << endl;
//   }
//   void
//   girl_init (string name1, int age1)
//   {
//     name = name1;
//     age = age1;
//   }
// };

// 类
class class_girl
{
public:
  string name;
  int age;
  void
  show ()
  {
    cout << "姓名: " << name << "\n年龄: " << age << endl;
  }
  void
  girl_init (string name1, int age1)
  {
    name = name1;
    age = age1;
  }
};
auto
main () -> int
{
  class_girl girls;
  girls.girl_init ("xiaomei", 15);
  girls.show ();
}