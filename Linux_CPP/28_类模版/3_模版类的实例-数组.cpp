// 类模板可以有非通用类型参数：1）通常是整型（C++20标准可以用其它）；
// 2）实例化模板时必须用常量表达式；
// 3）模板中不能修改参数的值；
// 4）可以为非通用类型参数提供默认值。
#include <iostream>
#include <string.h>
using namespace std;

template <class T, int len = 10> class Array
{
private:
  T items[len];

public:
  Array () { memset (items, 0, sizeof (items)); }
  ~Array () {}
  T &
  operator[] (int ii) // 重载操作符[] ,可以修改数组中的元素
  {
    return items[ii];
  }
  const T & // 重载操作符[] 不能修改数组中的元素
  operator[] (int ii) const
  {
    return items[ii];
  }
};

template <class T> class Vector
{
private:
  int len;
  T *items;

public:
  Vector (int size = 10) : len (size) { items = new T[len]; }
  ~Vector ()
  {
    delete[] items;
    items = nullptr;
  }
  void
  resize (int size)
  {
    if (size <= len)
      return;
    T *tmp = new T[size];
    for (int i = 0; i < len; i++)
      {
        tmp[i] = items[i];
      }
    delete[] items;
    items = tmp;
    len = size;
  }
  int
  size () const
  {
    return len;
  }
  T &
  operator[] (int ii) // 重载操作符[] ,可以修改数组中的元素
  {
    if (ii >= len)
      resize (ii + 10); // 扩展数组
    return items[ii];
  }
  const T & // 重载操作符[] 不能修改数组中的元素
  operator[] (int ii) const
  {
    return items[ii];
  }
};

int
main ()
{
  Vector<int> aa;
  aa[300] = 5;
  cout << aa[300] << endl;
}