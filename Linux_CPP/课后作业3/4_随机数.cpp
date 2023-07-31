// void srand(unsigned int seed);  	// 初始化随机数生成器（播种子）。
// int  rand();                    	// 获一个取随机数。

// 功能需求：
// 	写一个函数，随机生成n个整数，不允许重复。
// 	函数原型：
// void rrand(int arr[], const size_t len, const int minvalue=0);
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

void
rrand (int arr[], const size_t len, const int minvalue = 0)
{
  srand (time (0)); // 初始化随机种子
  for (int i = 0; i < len; i++)
    {
      while (1)
        {
          int tmp = rand () % len + minvalue;
          int j;
          for (j = 0; j < i; j++)
            if (tmp == arr[j])
              break;
          if (j == i)
            {
              arr[i] = tmp;
              break;
            }
        }
    }
}
auto
main () -> int
{
  // srand(time(0));
  // for(int i=0;i<10;i++)
  //   cout << rand() << endl;

  // 如果要生成 0—20的随机数
  // srand(time(0));
  // for(int i=0;i<10;i++)
  //   cout << rand()%20 << endl;

  // 如果要生成 20-70的随机数
  //  srand(time(0));
  // for(int i=0;i<10;i++)
  //   cout << rand()%(70-20)+20 << endl;
  int rand_value[10];
  memset(rand_value,0,sizeof(rand_value));
  rrand(rand_value,10,0);
  for(int i=0;i<sizeof(rand_value)/sizeof(int);i++)
    {
      cout <<i<<"= "<<rand_value[i]<<endl;
    }
}