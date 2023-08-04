// 纯虚函数只有函数名、参数和返回值类型，没有函数体，具体实现留给该派生类去做。
// 语法：virtual 返回值类型 函数名 (参数列表)=0;
// 纯虚函数在基类中为派生类保留一个函数的名字，以便派生类它进行重定义。如果在基类中没有保留函数名字，则无法支持多态性。

// 含有纯虚函数的类被称为抽象类，不能实例化对象，可以创建指针和引用。
// 派生类必须重定义抽象类中的纯虚函数，否则也属于抽象类。
// 基类中的纯虚析构函数也需要实现。


#include <iostream>
using namespace std;

class AA
{
public:
  AA()
  {
    cout << "调用了基类的构造函数AA()" << endl;
  }
  virtual void
  func() = 0;
  virtual
  ~AA()
  {
    cout << "调用了基类的析构函数~AA()" << endl;
  }
};

class BB : public AA
{
public:
  BB()
  {
    cout << "调用了派生类的构造函数BB()" << endl;
  }
  void
  func()
  {
    cout << "调用了派生类的func()" << endl;
  }
  ~BB()
  {
    cout << "调用了派生类的析构函数~BB()" << endl;
  }
};


int
main()
{
  BB b;
  AA* a = &b;
  a->func();

}