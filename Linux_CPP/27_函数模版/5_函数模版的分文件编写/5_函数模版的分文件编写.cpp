// 函数模板只是函数的描述，没有实体，创建函数模板的代码放在头文件中。
// 函数模板的具体化有实体，编译的原理和普通函数一样，所以，声明放在头文件中，定义放在源文件中。
#include "5_函数模版的分文件编写.h"
using namespace std;

void
Swap (int a, int b)
{
  cout << "使用了普通函数" << endl;
}

template <>
void
Swap (int a, int b)
{
  cout << "使用了具体化的函数模版" << endl;
}