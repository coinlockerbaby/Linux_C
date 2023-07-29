// 从界面上输入一个字符串（C风格），计算字符串的长度。如果输入的是"abcde"，显示的结果是5。
//  1）把计算字符串长度的功能封装成一个函数。
//  2）采用for循环，用数组表示法和临时变量计数。
//  3）采用while循环，用指针表示法和临时变量计数。
//  4）不用临时变量计数，用递归实现（奇巧淫技）。

#include <iostream>
#include <string.h>
using namespace std;

int
task_1 (char ch[])
{
  int len;
  for (len = 0; ch[len] != '\0'; len++)
    ;
  return len;
}

int
task_2 (char *ch)
{
  int len = 0;
  while (*(ch++))
    {
      len++;
    }
  return len;
}

//递归写法
int
task_3 (char *ch)
{
  // 递归结束条件
  if(!(*ch))
    return 0;
  return task_3(++ch)+1;
}

auto
main () -> int
{
  char ch[31] = "hello";
  cout << "len = " << task_3(ch) << endl;
}