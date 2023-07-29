// 有三个任务：
// 1）从界面上输入一个字母，显示该字母后面的字母，如果后面没有字母，给出提示。不允许用if…else if…和switch语句
// 2）自定义一个函数，把字符的'0'、'1'、'2'、'3'、'4'、'5'、'6'、'7'、'8'、'9'转换为整数的0、1、2、3、4、5、6、7、8、9。不允许用if…else if…和switch语句。
#include <iostream>
using namespace std;

void task_1(void)
{
    char ch;
    cout << "please input a char\n";
    cin >> ch;
    if(!(((ch>='A')&&(ch<='Z'))||((ch>='a')&&(ch<='z'))))
    {
        cout << "input error"<< endl;
    }
    else if((ch=='z')||(ch=='Z'))
    {
        cout << "next is null"<< endl;
    }
    else
    {
        cout << "the next char is: " << (char)(ch+1)<<endl;
    }

}

void task_2(void)
{
    
}
auto main() -> int
{
    task_1();
}