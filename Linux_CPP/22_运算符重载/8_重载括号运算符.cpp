// 括号运算符重载函数的语法：
// 返回值类型 operator()(参数列表);
// 注意：
// 括号运算符必须以成员函数的形式进行重载。
// 括号运算符重载函数具备普通函数全部的特征。
// 如果函数对象与全局函数同名，按作用域规则选择调用的函数。
#include <iostream>
using namespace std;

class girl
{
public:
  void
  operator() (string str)
  {
    cout << "类成员函数" << str << endl;
  }
};
void
show (string str)
{
  cout << "普通函数" << str << endl;
}
int
main ()
{
  show ("hello");
  girl g1;
  g1("hello");
}