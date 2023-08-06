// 1）auto声明的变量必须在定义时初始化。
// 2）初始化的右值可以是具体的数值，也可以是表达式和函数的返回值等。
// 3）auto不能作为函数的形参类型。
// 4）auto不能直接声明数组。
// 5）auto不能定义类的非静态成员变量。
#include <iostream>
using namespace std;

double
func (int a, double b, const char *c, float d, short e, long f)
{
  cout << "a=" << a << ",b=" << b << ",c=" << c << ",d=" << d << ",e=" << e
       << ",f=" << f << endl;
  return 5.5;
}

auto
main () -> int
{
  double (*pf) (int, double, const char *, float, short, long);
  pf = func;
  pf (1, 2, "西施", 3, 4, 5);
  //上面与下面的效果一样 auto类型自动推导为函数指针
  auto pf1 = func;
  pf1 (1, 2, "西施", 3, 4, 5);
}