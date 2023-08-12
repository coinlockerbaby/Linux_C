// 使用两种方式定义常量

#include <iostream>
#define MONTH "12"
using  namespace std;

int
main ()
{
  const int day = 7;
  cout << MONTH << endl;
  cout << day << endl;
}