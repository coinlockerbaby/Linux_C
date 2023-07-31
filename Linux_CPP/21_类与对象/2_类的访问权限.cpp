// 类的成员有三种访问权限：public、private和protected，分别表示公有的、私有的和受保护的。
// 在类的内部（类的成员函数中），无论成员被声明为 public还是private，都可以访问。
// 在类的外部（定义类的代码之外），只能访问public成员，不能访问 private、protected成员。
// 在一个类体的定义中，private 和 public 可以出现多次。
// 结构体的成员缺省为public，类的成员缺省为private。
// private的意义在于隐藏类的数据和实现，把需要向外暴露的成员声明为public。
#include <iostream>
using namespace std;

// 类
class class_girl
{
public:
  string name;
private:
  int age;
public:
  void
  show ()
  {
    cout << "姓名: " << name << "\n年龄: " << age << endl;
  }
private:
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
