#include <iostream>
using namespace std;

class girl
{
private:
  string m_boy[3];

public:
  string m_name;
  girl ()
  {
    m_boy[0] = "子都";
    m_boy[1] = "潘安";
    m_boy[2] = "宋玉";
  }
  // 显示全部男朋友的姓名
  void
  show ()
  {
    cout << m_boy[0] << m_boy[1] << m_boy[2] << endl;
  }
  string &
  operator[] (int i)
  {
    return m_boy[i];
  }
};

auto
main () -> int
{
  girl g1;
  g1[0] = "元神";
  cout << "第1任男朋友" << g1[0] << endl;
  g1.show ();
}