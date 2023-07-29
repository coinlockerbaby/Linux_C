// 有两个任务：
// 1）采用一个while循环，把1到100之间的数值累加起来。
// 2）采用一个for循环，把用户每次从键盘输入的数值累加起来，如果总和超过了5000，循环结束。
#include <iostream>
using namespace std;

void
task_1 (void)
{
  int i = 1;
  int sum = 0;
  while (i <= 100)
    {
      sum += i;
      i++;
    }
  cout << "sum = " << sum << endl;
}

void
task_2 (void)
{
  int input = 0;
  int sum = 0;
  for (; sum <= 5000;)
    {
      cout << "please input int num: ";
      cin >> input;
      sum += input;
      cout << "this time sum: " << sum << endl;
    }
  cout << "sum = " << sum << " over 5000" << endl;
}

auto
main () -> int
{
  task_2 ();
}