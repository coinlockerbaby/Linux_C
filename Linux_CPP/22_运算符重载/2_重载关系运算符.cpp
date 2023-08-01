// 重载关系运算符（==、!=、>、>=、<、<=）用于比较两个自定义数据类型的大小。
#include <iostream>
using namespace std;

class girl
{
private:
  string m_name;
  int m_yz;
  int m_sc;

public:
  girl (string name, int yz, int sc) : m_name (name), m_yz (yz), m_sc (sc)
  {
    ;
  }

  bool
  operator== (const girl &girl2)
  {
    if ((this->m_sc + this->m_yz) == (girl2.m_sc + girl2.m_yz))
      {
        return true;
      }
    else
      return false;
  }

  bool
  operator> (const girl &girl2)
  {
    if ((this->m_sc + this->m_yz) < (girl2.m_sc + girl2.m_yz))
      {
        return true;
      }
    else
      return false;
  }
// 以成员函数重载运算符时，对象本身作为一个参数隐式传入
  bool
  operator< (const girl &girl2)
  {
    if ((this->m_sc + this->m_yz) > (girl2.m_sc + girl2.m_yz))
      {
        return true;
      }
    else
      return false;
  }
};

auto
main () -> int
{
  girl g1 ("李华", 100, 100);
  girl g2 ("小明", 100, 100);
  cout << (g1>g2) << endl;
}
