#include <iostream>
using namespace std;

// 基类
class CALLComers // 海选报名类
{
public:
  string m_name;
  string m_tel;

  // 构造函数
  CALLComers () : m_name ("某女"), m_tel ("不详") { ; }
  // 普通成员函数
  void
  sing ()
  {
    cout << "我是一只小小鸟\n";
  }
  void
  setname (const string &name)
  {
    m_name = name;
  }
  void
  settel (const string &tel)
  {
    m_tel = tel;
  }
};
// 派生类
class girl : public CALLComers
{
public:
  int m_bh;
  girl () : m_bh (8) { ; }
  void
  show()
  {
    cout << "编号: " << m_bh << ", 姓名: " << m_name << ", 联系电话: " << m_tel << endl;
  }
};

int
main()
{
  girl g1;
  g1.setname("西施");
  g1.settel("123465");
  g1.show();
}