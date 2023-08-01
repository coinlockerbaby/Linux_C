// C++将运算符重载扩展到自定义的数据类型
// 运算符重载函数的语法：返回值 operator运算符(参数列表);
// 运算符重载函数的返回值类型最好要与运算符本身的含义一致。
// 运算符重载函数最好放在类里面（成员函数）
#include <iostream>
using namespace std;

class girl
{
  friend void operator+ (girl &g, int score);
  friend girl& operator- (girl &g, int score);
private:
  int m_xw;
  int m_score;

public:
  string m_name;
  girl ()
  {
    m_name = "西施";
    m_xw = 87;
    m_score = 30;
  }
  void
  show ()
  {
    cout << "姓名: " << m_name << ", 胸围: " << m_xw << ", 分数: " << m_score
         << endl;
  }
};

void
operator+ (girl &g, int score)
{
  g.m_score += score;
}

girl&
operator- (girl &g, int score)
{
  g.m_score -= score;
  return g;
}
auto
main () -> int
{
  girl g1;
  g1 + 30;
  g1.show ();
  g1 = g1-60;
  g1.show ();
}