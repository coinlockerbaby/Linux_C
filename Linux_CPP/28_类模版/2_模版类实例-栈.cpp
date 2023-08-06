// 创建模版类的方法
// 先写一个普通类
// 调试普通类
// 把普通类改为模版类

#include <iostream>
using namespace std;


template <class Datatype>
class Stack
{
private:
  Datatype *items;    //   栈数组
  int stacksize; // 栈实际大小
  int top;       // 栈顶指针
public:
  Stack (int size) : stacksize (size), top (0) { items = new Datatype[stacksize]; }
  ~Stack ()
  {
    delete[] items;
    items = nullptr;
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

auto
main () -> int
{
  Stack <string> ss(5);
  // 元素入栈
  ss.push("lihua");
  ss.push("xiaoming");
  ss.push("huahua");
  ss.push("yuanshen");
  ss.push("qidong");
  // 元素出栈
  string item;
  while(ss.isempty() == false)
  {
    ss.pop(item);
    cout << "item=" << item << endl;
  }
}