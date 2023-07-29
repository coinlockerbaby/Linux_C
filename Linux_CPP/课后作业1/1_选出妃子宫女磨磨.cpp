// 在界面上输入超女数据后，按下列要求选出妃子、宫女和嬷嬷。
// 妃子：1）年龄18-25岁；2）身高165-178cm；3）身材火辣；4）颜值漂亮。
// 宫女：1）年龄18-30岁；2）身高160-165cm；3）身材火辣或者普通；4）颜值漂亮。
// 嬷嬷：1）年龄35-40岁；2）身高155-165cm；3）身材普通或者飞机场；4）颜值一般。
// 其它要求：
// 1）超女数据用结构体表示；
//     struct st_girl {
//         int age;
//         int height;
//         string sc;     // C++风格字符串。
//         //char sc[31];  // C风格字符串。
//         bool yz;	// true-漂亮；false-一般。
//     } stgirl;
// 2）先输入超女全部的数据项，然后才进行选秀；
// 3）用逻辑表达式组合判断条件，不要用嵌套if语句。
#include <iostream>
using namespace std;

typedef struct
{
  int age;
  int height;
  string sc; // 如果想用c语言字符数组的话请将下面的 girl.sc == "xxx"改为
             // strcmp(girl.sc, "xxx"); 并加上string.h头文件
  bool yz; // 颜值 1漂亮 2一般
} st_girl;

int
main ()
{
  while (1)
    {
      st_girl girl;
      cout << "please input girl age\n";
      cin >> girl.age;
      cout << "please input girl height\n";
      cin >> girl.height;
      cout << "please input girl sc\n";
      cin >> girl.sc;
      cout << "please input girl yz\n";
      cin >> girl.yz;
      cout << "girl.age = " << girl.age << "\ngirl.height = " << girl.height
           << "\ngirl.sc = " << girl.sc << "\ngirl.yz = " << girl.yz << endl;
      if (((girl.age >= 18) && (girl.age <= 25))
          && ((girl.height >= 165) && (girl.height <= 178))
          && (girl.sc == "火辣") && (girl.yz == 1))
        {
          cout << "你输入的是妃子" << endl;
        }
      else if (((girl.age >= 18) && (girl.age <= 30))
               && ((girl.height >= 160) && (girl.height <= 165))
               && ((girl.sc == "火辣") || (girl.sc == "普通"))
               && (girl.yz == 1))
        {
          cout << "你输入的是宫女" << endl;
        }
      else if (((girl.age >= 35) && (girl.age <= 40))
               && ((girl.height >= 155) && (girl.height <= 165))
               && ((girl.sc == "普通") || (girl.sc == "飞机场"))
               && (girl.yz == 0))
        {
          cout << "你输入的是磨磨" << endl;
        }
      else
        cout << "error please try agin\n";
    }
}
