// 从界面上输入一个字符串（C风格），把字符串中的每个字符显示出来，如果输入的是"abc"，要求：
// 1）正序显示：a b c
// 2）逆序显示：c b a
#include <iostream>
using namespace std;

auto
main () -> int
{
  char ch[3] = { 'a', 'b', 'c' };
  // 正顺显示
  for (int i = 0, len = (sizeof (ch) / sizeof (ch[0])); i < len; i++)
    {
      cout << ch[i] << ' ';
    }
  cout << endl;

  // 逆序显示
  for (int i = sizeof (ch) / sizeof (ch[0]) - 1; i >= 0; i--)
    {
      cout << ch[i] << ' ';
    }
  cout << endl;
}