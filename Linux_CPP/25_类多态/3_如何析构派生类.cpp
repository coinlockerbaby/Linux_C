#include <iostream>
using namespace std;

class AA
{
public:
  AA () { cout << "调用了基类的构造函数AA()" << endl; }
  virtual void
  func ()
  {
    cout << "调用了基类的func()" << endl;
  }
  ~AA () { cout << "调用了基类的析构函数~AA()" << endl; }
};

class BB : public AA
{
public:
  BB () { cout << "调用了派生类的构造函数BB()" << endl; }
  void
  func ()
  {
    cout << "调用了派生类的func()" << endl;
  }
  ~BB () { cout << "调用了派生类的析构函数~BB()" << endl; }
};

int
main ()
{
  // 如果用基类指针指向派生类对象，delete指针时，只有基类会调用析构函数
  // 如果解决？   anser: 把基类的析构函数设置为虚函数 virtual ~AA()
  AA* ptr = new BB;
  delete ptr;
}