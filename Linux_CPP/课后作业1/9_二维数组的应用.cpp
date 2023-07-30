// 有两个任务：
// 1）超女有3个小组，每组有4名选手，请提供一个界面，输入每个超女的体重，然后，计算出每组的超女的平均体重和全部超女的平均体重。
// 2）从界面上输出三个超女的姓名，存放在C风格的字符串数组中，然后，分别向她们表白。
#include <iostream>
#include <string.h>
using namespace std;

void
task_1 (void)
{
  double weight[3][4];
  memset (weight, 0, sizeof (weight));
  cout << "please input girls weight\n";
  for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 4; j++)
        {

          cout << "please input " << i << "row " << j << "col girl weight\n";
          cin >> weight[i][j];
        }
    }
  double totol_weight = 0; // 总体重
  for (int i = 0; i < 3; i++)
    {
      double row_weight = 0; // 每组体重
      for (int j = 0; j < 4; j++)
        {
          row_weight += weight[i][j];
        }
      cout << "the " << i << "row weight =" << row_weight << endl;
      cout << "the " << i << "row avg_weight =" << row_weight / 4 << endl;
      totol_weight += row_weight;
    }
  cout << "the totol weight: " << totol_weight << endl;
}

void
task_2 (void)
{
  char ch[3][31];
  memset (ch, 0, sizeof (ch));
  for (int i = 0; i < 3; i++)
    {
      cout << "please input " << i << " name: ";
      cin >> ch[i];
    }
  for (int i = 0; i < 3; i++)
    {
      cout << "hello " << ch[i] << endl;
    }
}
auto
main () -> int
{
  task_2 ();
}