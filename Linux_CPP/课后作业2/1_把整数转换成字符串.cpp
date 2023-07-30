// 把整数转换成字符串
// 从界面上输入一个整数，把它转换为十进制和八进制的C风格的字符串。
#include <iostream>
#include <string.h>

using namespace std;

void
task_1 (void)
{
  int input_value = 0;
  char DEC_value[21];
  memset (DEC_value, 0, sizeof (DEC_value));
  cout << "输入一个整数" << endl;
  cin >> input_value;
  for (int i = 0; input_value != 0; i++)
    {
      DEC_value[i] = input_value % 10 + '0'; //通过’0’定位 ascii码
      input_value = input_value / 10;
    }
  
  // 逆序字符数组 使用不借助其它字符数组的方法能节约内存
  for (int i = 0, len = strlen (DEC_value); i < len / 2; i++)
    {
      char temp;
      temp = DEC_value[len - 1 - i];
      DEC_value[len - 1 - i] = DEC_value[i];
      DEC_value[i] = temp;
    }
  cout << DEC_value << endl;
}

void
task_2(void)
{
  int input_value = 0;
  char OCT_value[21];
  memset (OCT_value, 0, sizeof (OCT_value));
  cout << "输入一个整数" << endl;
  cin >> input_value;
  for (int i = 0; input_value != 0; i++)
    {
      OCT_value[i] = input_value % 8 + '0'; // 通过’0’定位 ascii码
      input_value = input_value / 8;
    }

  // 逆序字符数组 使用不借助其它字符数组的方法能节约内存
  for (int i = 0, len = strlen (OCT_value); i < len / 2; i++)
    {
      char temp;
      temp = OCT_value[len - 1 - i];
      OCT_value[len - 1 - i] = OCT_value[i];
      OCT_value[i] = temp;
    }
  cout << OCT_value << endl;
}
auto
main () -> int
{
  task_2 ();
}