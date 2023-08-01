///////////////////////////////////////////////////////////////////////////////////////

#include <iostream>         // 包含头文件。
using namespace std;        // 指定缺省的命名空间。

class CGirl;      // 把超女类的声明前置

class CBoy    // 超女的男朋友类
{
public:
    void func1(const CGirl& g);
    void func2(const CGirl& g);
};

class CGirl       // 超女类CGirl。
{
    friend void CBoy::func1(const CGirl& g);
    // friend void CBoy::func2(const CGirl& g);
public:
    string    m_name;   // 姓名。
    // 默认构造函数。
    CGirl() { m_name = "西施";  m_xw = 87; }
    // 显示姓名的成员函数。
    void showname() { cout << "姓名：" << m_name << endl; }
private:
    int         m_xw;        // 胸围。
    // 显示胸围的成员函数。
    void showxw() const { cout << "胸围：" << m_xw << endl; }
};

void CBoy::func1(const CGirl& g) { cout << "func1()我女朋友的胸围是：" << g.m_xw << endl; }
void CBoy::func2(const CGirl& g) { cout << "func2()我女朋友的姓名是：" << g.m_name << endl; }

int main()
{
    CGirl g;
    CBoy b;
    b.func2(g);
    b.func1(g);
}