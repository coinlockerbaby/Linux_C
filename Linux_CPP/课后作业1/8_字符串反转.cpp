// 从界面上输入一个C风格的字符串，如果输入的是"abc"，反转后"cba"。
// 1）反转的结果存放在另一字符串中。
// 2）原地反转，不借助其它的字符串。
#include <iostream>
#include <string.h>
using namespace std;

void
task_1 (void)
{
  char ch[31];
  char ch2[31];
  memset (ch, 0, sizeof (ch));
  memset (ch2, 0, sizeof (ch2));
  cout << "please input value: ";
  cin >> ch;
  for (int i = strlen (ch) - 1; i >= 0; i--)
    {
      ch2[strlen (ch) - 1 - i] = ch[i];
    }
  cout << ch2 << endl;
}

void
task_2 (void)
{
  char ch[31];
  memset (ch, 0, sizeof (ch));
  cout << "please input char: ";
  cin >> ch;
  for (int i = 0, len = strlen (ch); i < len / 2; i++)
    {
      char temp;
      temp = ch[i];
      ch[i] = ch[len-1-i];
      ch[len-1-i] = temp;
    }
  cout << ch << endl;
}

auto
main () -> int
{
  task_2 ();
}