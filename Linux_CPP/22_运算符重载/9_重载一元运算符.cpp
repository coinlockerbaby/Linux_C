#include <iostream>
using namespace std;

class girl
{
public:
  string m_name;
  int    m_rank;
  girl()
  {
    m_name = "西施";
    m_rank = 5;
  }    
  void
  show() const
  {
    cout << "姓名: "<< m_name << ", 排名: " << m_rank << endl;
  }
  girl&
  operator ++ ()
  {
    m_rank++;
    return *this;
  }
  //C++ 规定，重载++或--时，如果重载函数有一个int形参，编译器处理后置表达式时将调用这个重载函数。
  girl
  operator ++ (int)
  {
    // 为了匹配后置++的性质，进行处理
    girl temp = *this; // temp和this的地址不同但是值相同
    m_rank++; // this的m_rank++
    return temp; // 返回没有++的temp
  }
};


auto
main()->int
{
  girl g1;
  girl g2;

  g2 = g1++;
  cout << "g1.m_rank= " <<g1.m_rank<<"g2.m_rank= " <<g2.m_rank <<endl;
}