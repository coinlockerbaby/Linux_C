#include <iostream>
#include <string.h>
using namespace std;

template <class Datatype> class Stack
{
private:
  Datatype *items; //   栈数组
  int stacksize;   // 栈实际大小
  int top;         // 栈顶指针
public:
  Stack (int size = 3) : stacksize (size), top (0)
  {
    items = new Datatype[stacksize];
  }
  ~Stack ()
  {
    delete[] items;
    items = nullptr;
  }
  // 重载赋值运算函数实现深拷贝
  Stack &
  operator= (const Stack &v)
  {
    delete[] items;
    stacksize = v.stacksize;
    items = new Datatype[stacksize];
    for (int ii = 0; ii < stacksize; ii++)
      {
        items[ii] = v.items[ii];
      }
    top = v.top;
    return *this;
  }

  // 判断栈是否为空
  bool
  isempty () const
  {
    return top == 0;
  }
  // 判断栈是否满
  bool
  isfull () const
  {
    return top == stacksize;
  }
  // 入栈
  bool
  push (const Datatype &item)
  {
    if (top < stacksize)
      {
        items[top++] = item;
        return true;
      }
    return false;
  }
  // 出栈
  bool
  pop (Datatype &item)
  {
    if (top > 0)
      {
        item = items[--top];
        return true;
      }
    return false;
  }
};

template <class T> class Vector
{
private:
  int len;
  T *items;

public:
  Vector (int size = 2) : len (size) { items = new T[len]; }
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
        tmp[i] = items[i]; // 因为这里复制的是类，所以会出现浅拷贝问题
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
      resize (ii + 1); // 扩展数组
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
  // Vector容器大小缺省值是2 stack容器大小的缺省值是3
  Vector<Stack<string> > vs;
  // 手工往容器中插入数据
  vs[0].push ("西施1");
  vs[0].push ("西施2");
  vs[0].push ("西施3");
  vs[1].push ("西施1");
  vs[1].push ("西施2");
  vs[1].push ("西施3");
  vs[2].push ("西施1");
  vs[2].push ("西施2");
  vs[2].push ("西施3");
  // 用嵌套循环把容器中的数据显示出来
  for (int i = 0; i < vs.size (); i++)
    {
      while (vs[i].isempty () == false)
        {
          string item;
          vs[i].pop (item);
          cout << "item=" << item << endl;
        }
    }
}