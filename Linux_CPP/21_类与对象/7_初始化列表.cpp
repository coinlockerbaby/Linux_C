#include <iostream>

using namespace std;

class boy
{
public:
  string m_xm; // 姓名
  boy ()
  {
    m_xm.clear ();
    cout << "调用了boy类的构造函数" << endl;
  }
  boy (string xm)
  {
    m_xm = xm;
    cout << "调用了boy类带参数的构造函数" << endl;
  }
  boy (const boy &bb)
  {
    m_xm = bb.m_xm;
    cout << "调用了boy类的拷贝构造函数" << endl;
  }
};

class girl
{
public:
  string m_name;
  int m_age;
  boy m_boy;

  girl () { cout << "调用girl类构造函数" << endl; }
  girl (string name, int age, boy& boy1)
  :m_name(name),m_age(age),m_boy(boy1)
  {
    //m_boy.m_xm = boy1.m_xm;
    cout << "调用了带参数的girl类构造函数" << endl;
  }
  void
  show ()
  {
    cout << "姓名: " << m_name << "\n年龄: " << m_age << "\n男朋友: " << m_boy.m_xm
         << endl;
  }
};

int
main ()
{
  boy boy1 ("原神");
  girl girls ("王者", 12, boy1);
  girls.show ();
}