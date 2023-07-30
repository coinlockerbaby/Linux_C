// 有两个任务：
// 1）为了支持把C风格的字符串转换成数字，C++提供了以下四个函数：
// int atoi(const char *_String);			// 把C风格字符串转换为int整数。
// long atol(const char *_String);			// 把C风格字符串转换为long整数。
// long long atoll(const char *_String);	// 把C风格字符串转换为long long整数。
// double atof(const char *_String);		// 把C风格字符串转换为double浮点数。
// 注意：a）如果字符串中间有非法字符，后面的内容将丢弃；b）如果字符串的第一个字符非法或字符串为空，将返回0。
// 2）从界面上输入一个C风格的字符串（二进制或十进制），把它转换成整数，类似atoi()函数。
#include <iostream>
#include <string.h>

using namespace std;

void
task_1(void)
{
  cout << atoi("123") + atoi("456")<<endl;
}
void
task_2(void)
{
  char input[31];
  int jinzhi = 0;
  memset(input,0,sizeof(input));
  long long result = 0;
  cout << "input: ";
  cin >> input;
  cout << "输入进制数: ";
  cin >> jinzhi;
  for(int i=0,len=strlen(input);i<len;i++)
  {
    result *=jinzhi; // 第一位是 0×10=0
    result += input[i]-'0';
  }
  cout << result <<endl;
}

auto main()->int
{
  task_2();
}