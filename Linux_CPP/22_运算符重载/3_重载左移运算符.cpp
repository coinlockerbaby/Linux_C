#include <iostream>
using namespace std;

class girl
{
  friend ostream &operator<< (ostream &cout, const girl &g);

private:
  string m_name;
  int m_xw;
  int m_score;

public:
  girl ()
  {
    m_name = "西施";
    m_xw = 12;
    m_score = 13;
  }
  void
  show ()
  {
    cout << "姓名: " << this->m_name << ", 胸围: " << this->m_xw
         << ", 评分: " << this->m_score << endl;
  }
};

ostream &
operator<< (ostream &cout, const girl &g)
{
  cout << "姓名: " << g.m_name << ", 胸围: " << g.m_xw
       << ", 评分: " << g.m_score << endl;
  return cout;
}

auto
main () -> int
{
  girl g1;
  cout << g1;
}