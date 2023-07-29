// 有三个任务：
// 1）从界面上输入一个字母，显示该字母后面的字母，如果后面没有字母，给出提示。不允许用if…else
// if…和switch语句
// 2）自定义一个函数，把字符的'0'、'1'、'2'、'3'、'4'、'5'、'6'、'7'、'8'、'9'转换为整数的0、1、2、3、4、5、6、7、8、9。不允许用if…else
// if…和switch语句。
// 3）实现字符操作常用库函数的功能，如下：
// int isalpha(int ch);   
// // 若ch是字母（'A'-'Z','a'-'z'）返回非0，否则返回0。 int isalnum(int ch);
// // 若ch是字母（'A'-'Z','a'-'z'）或数字（'0'-'9'），返回非0，否则返回0。
// int isdigit(int ch);   
// // 若ch是数字（'0'-'9'）返回非0，否则返回0。 int islower(int ch);   
// // 若ch是小写字母（'a'-'z'）返回非0，否则返回0。 int isupper(int ch);   
// // 若ch是大写字母（'A'-'Z'）返回非0，否则返回0。 int tolower(int ch);   
// // 若ch是大写字母（'A'-'Z'），则返回它的小写字母（'a'-'z'）。
// int toupper(int ch);   
// // 若ch是小写字母（'a'-'z'），则返回它的大写字母（'A'-'Z'）。
#include <iostream>
using namespace std;

// 1）从界面上输入一个字母，显示该字母后面的字母，如果后面没有字母，给出提示。不允许用if…else
void
task_1 (void)
{
  char ch;
  cout << "please input a char\n";
  cin >> ch;
  if (!(((ch >= 'A') && (ch <= 'Z')) || ((ch >= 'a') && (ch <= 'z'))))
    {
      cout << "input error" << endl;
    }
  else if ((ch == 'z') || (ch == 'Z'))
    {
      cout << "next is null" << endl;
    }
  else
    {
      cout << "the next char is: " << (char)(ch + 1) << endl;
    }
}
// 2）自定义一个函数，把字符的'0'、'1'、'2'、'3'、'4'、'5'、'6'、'7'、'8'、'9'转换为整数的0、1、2、3、4、5、6、7、8、9。不允许用if…else
// if…和switch语句。
int
task_2 (char ch)
{
  return ch - '0';
}

// 3)
//  int isalpha(int ch);   
//  // 若ch是字母（'A'-'Z','a'-'z'）返回非0，否则返回0。 int isalnum(int ch);
//  // 若ch是字母（'A'-'Z','a'-'z'）或数字（'0'-'9'），返回非0，否则返回0。
//  int isdigit(int ch);   
//  // 若ch是数字（'0'-'9'）返回非0，否则返回0。 int islower(int ch);   
//  // 若ch是小写字母（'a'-'z'）返回非0，否则返回0。 int isupper(int ch);   
//  // 若ch是大写字母（'A'-'Z'）返回非0，否则返回0。 int tolower(int ch);   
//  // 若ch是大写字母（'A'-'Z'），则返回它的小写字母（'a'-'z'）。
//  int toupper(int ch);   
//  // 若ch是小写字母（'a'-'z'），则返回它的大写字母（'A'-'Z'）。

int
isalpha (int ch)
{
  if (!(((ch >= 'a') && (ch <= 'z'))) || ((ch >= 'A') && (ch <= 'Z')))
    {
      return 0;
    }
  else
    return 1;
}

int
isalnum (int ch)
{
  if (!((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
      || (ch >= '1' && ch <= '9'))
    {
      return 0;
    }
  else
    return 1;
}

int
isdigit (int ch)
{
  if (!(ch > '0' && ch <= '9'))
    {
      return 0;
    }
  else
    return 1;
}

int
islower (int ch)
{
  if (!(ch >= 'a' && ch < 'z'))
    {
      return 0;
    }
  else
    return 1;
}

int
isupper (int ch)
{
  if (!(ch > 'A' && ch < 'Z'))
    {
      return 0;
    }
  else
    return 1;
}

int
to_lower (int ch)
{
  if (ch >= 'A' && ch <= 'Z')
    {
      return ch + 32;
    }
  else
    return ch;
}

int
to_upper (int ch)
{
  if (ch >= 'a' && ch <= 'z')
    {
      return ch - 32;
    }
  else
    return ch;
}

auto
main () -> int
{
  exit(0);
}