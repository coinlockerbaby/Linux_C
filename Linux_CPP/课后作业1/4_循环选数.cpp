// 有两个任务：
// 1）用一个while循环，接受从键盘输入的整数，如果输入的整数不在1到100之间（包括1和100），认为无效，丢弃；如果输入的整数在1到100之间，则把每次输入的值累加起来；如果输入的整数为0，跳出循环。最后，显示有效数据的个数和总和。
// 2）输出1到100之间（包括1和100）的能整除5的数字。
#include <iostream>
using namespace std;

void
task_1(void)
{
    int input_num;
    int sum = 0;
    int ii = 0;// 有效数字个数
    while(1)
    {
        cout << "input num: ";
        cin >> input_num;
        if(input_num>=1&&input_num<=100)
        {
            sum += input_num;
            ii++;
        }
        else if(input_num == 0)
        {
            break;
        }
        else
        {
            continue;
        }
    }
    cout << "sum = " << sum <<"\n有效数据个数 = "<< ii << endl;
}

void
task_2(void)
{
    for(int i=1;i<=100;i++)
    {
        if (i%5==0)
        {
            cout << i <<" ";
        }
    }
    cout << endl;
}

auto
main()->int
{
    task_2();
}
