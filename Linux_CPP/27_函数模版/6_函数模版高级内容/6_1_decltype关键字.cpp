// 在C++11中，decltype操作符，用于查询表达式的数据类型。
// 语法：decltype(expression) var;
// decltype分析表达式并得到它的类型，不会计算执行表达式。函数调用也一种表达式，因此不必担心在使用decltype时执行了函数。

// 1）如果expression是一个没有用括号括起来的标识符，则var的类型与该标识符的类型相同，包括const等限定符。
// 2）如果expression是一个函数调用，则var的类型与函数的返回值类型相同（函数不能返回void，但可以返回void *）。
// 3）如果expression是一个左值（能取地址）(要排除第一种情况)、或者用括号括起来的标识符，那么var的类型是expression的引用。
// 4）如果上面的条件都不满足，则var的类型与expression的类型相同。
// 如果需要多次使用decltype，可以结合typedef和using。


// 函数后置返回类型
// int func(int x, double y);
// 等同于
// auto func(int x, double y) -> int;

#include <iostream>
using namespace std;

int
func()
{
  return 3;
}

auto
main()->int
{
  short a = 5;
  decltype(func()) ;
}

