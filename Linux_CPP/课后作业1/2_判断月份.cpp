// 在界面上输入数字的月份（1-12），输出对应月份的英文单词的全称，如果输入的数字不合法，给出提示。
// 其它要求：
// 1）用if … else if …实现；
// 2）用switch实现；
// 3）用字符串数组（C风格和C++风格）实现。
#include <iostream>
using namespace std;
// if else if 实现
// auto main()->int
// {
//     int month;
//     cout << "Enter a month (1-12): ";
//     cin >> month;
//     if(month == 1)
//     {
//         cout << "January"<< endl;
//     }
//     else if(month == 2)
//     {
//         cout << "February"<< endl;
//     }
//     else if(month == 3)
//     {
//         cout << "March"<< endl;
//     }
//     else if(month == 4)
//     {
//         cout << "April"<< endl;
//     }
//     else if(month == 5)
//     {
//         cout << "May"<< endl;
//     }
//     else if(month == 6)
//     {
//         cout << "June"<< endl;
//     }
//     else if(month == 7)
//     {
//         cout << "July"<< endl;
//     }
//     else if(month == 8)
//     {
//         cout << "August"<< endl;
//     }
//     else if(month == 9)
//     {
//         cout << "September"<< endl;
//     }
//     else if(month == 10)
//     {
//         cout << "October"<< endl;
//     }
//     else if(month == 11)
//     {
//         cout << "November"<< endl;
//     }
//     else if (month ==12)
//     {
//         cout << "December"<< endl;
//     }
//     else
//     {
//         cout << "Invalid month"<< endl;
//     }

// }

// switch 实现
// auto main()->int
// {
//     int month;
//     cout << "Enter a month (1-12): ";
//     cin >> month;
//     switch(month)
//     {
//         case 1:
//         cout << "January\n";
//         break;
//         case 2:
//         cout << "February\n";
//         break;
//         case 3:
//         cout << "March\n";
//         break;
//         case 4:
//         cout << "April\n";
//         break;
//         case 5:
//         cout << "May\n";
//         break;
//         case 6:
//         cout << "June\n";
//         break;
//         case 7:
//         cout << "July\n";
//         break;
//         case 8:
//         cout << "August\n";
//         break;
//         case 9:
//         cout << "September\n";
//         break;
//         case 10:
//         cout << "October\n";
//         break;
//         case 11:
//         cout << "November\n";
//         break;
//         case 12:
//         cout << "December\n";
//         break;
//         default:
//         cout << "Invalid month\n";
//         break;
//     }
// }

// c++ string 字符串数组实现
// 这边数组初始化可以直接赋值，我第一次写的时候忘了
// auto main()->int
// {
//     int month;
//     cout << "Enter a month (1-12): ";
//     cin >> month;
//     string english_month[13];
//     english_month[1] = "January";
//     english_month[2] = "February";
//     english_month[3] = "March";
//     english_month[4] = "April";
//     english_month[5] = "May";
//     english_month[6] = "June";
//     english_month[7] = "July";
//     english_month[8] = "August";
//     english_month[9] = "September";
//     english_month[10] = "October";
//     english_month[11] = "November";
//     english_month[12] = "December";
//     if(month >=1 && month <=12)
//     cout << english_month[month] << endl;
//     else
//     cout << "Invalid month\n";
// }

// c char数组 字符串数组实现
auto main() -> int
{
    int month;
    cout << "Enter a month (1-12): ";
    cin >> month;
    char english_month_array[12][10] = {{"January"}, {"February"}, {"March"}, {"April"}, {"May"}, {"June"}, {"August"}, {"September"}, {"October"}, {"Noverber"}, {"December"}};
    if (month >= 1 && month <= 12)
        cout << english_month_array[month - 1] << endl;
    else
        cout << "Invalid month\n";
}