#ifndef __HEAD_H__
#define __HEAD_H__
#include <iostream>
using namespace std;
// 普通函数
void Swap (int a, int b);

// 函数模版
template <typename T>
void
Swap (T a, T b)
{
  cout << "使用了函数模版" << endl;
}

// 具体化函数模版
template <> void Swap (int a, int b);
#endif