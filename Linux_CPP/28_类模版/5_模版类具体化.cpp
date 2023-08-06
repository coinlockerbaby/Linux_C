#include <iostream>
#include <string.h>

using namespace std;

template <class T1, class T2> class AA
{
public:
  T1 m_x;
  T2 m_y;
  AA (const T1 x, const T2 y) : m_x (x), m_y (y)
  {
    cout << "类模版:构造函数" << endl;
  }
  void show () const;
};

template <class T1, class T2>
void
AA<T1, T2>::show () const
{
  cout << "类模版: x=" << m_x << ",y=" << m_y << endl;
}

// 类模版完全具体化
template <> class AA<int, string>
{
public:
  int m_x;
  string m_y;
  AA (const int x, const string y) : m_x (x), m_y (y)
  {
    cout << "完全具体化:构造函数" << endl;
  }
  void show () const;
};

void
AA<int, string>::show () const
{
  cout << "完全具体化: x=" << m_x << ",y=" << m_y << endl;
}

// 类模版部分具体化
template <class T1> class AA<T1, string>
{
public:
  T1 m_x;
  string m_y;
  AA (const T1 x, const string y) : m_x (x), m_y (y)
  {
    cout << "部分具体化: 构造函数" << endl;
  }
  void
  show() const;
};

template <class T1>
void AA<T1,string>::show() const
{
  cout << "部分具体化: x=" << m_x << ",y=" << m_y << endl;
}

int
main ()
{
  AA <int,string> aa(8,"原神启动");
  aa.show();

}