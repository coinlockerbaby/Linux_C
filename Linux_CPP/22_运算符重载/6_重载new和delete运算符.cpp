// 注意 new和delete函数只能访问静态成员
#include <iostream>
using namespace std;

void *
operator new (size_t size)
{
  cout << "调用了全局重载的new: " << size << "字节" << endl;
  void *ptr = malloc (size);
  cout << "申请到的内存地址是: " << ptr << endl;
  return ptr;
}
void
operator delete (void *ptr)
{
  cout << "调用了全局重载的delete" << endl;
  if (ptr == 0)
    return;
  free (ptr);
}
class girl
{
public:
  int m_bh; // 编号
  int m_xw; // 胸围
  girl (int bh, int xw) : m_bh (bh), m_xw (xw) { ; }
  ~girl () { cout << "调用了析构函数" << endl; }
  void *
  operator new (size_t size)
  {
    cout << "调用了类重载的new: " << size << "字节" << endl;
    void *ptr = malloc (size);
    cout << "申请到的内存地址是: " << ptr << endl;
    return ptr;
  }
  void
  operator delete (void *ptr)
  {
    cout << "调用了类重载的delete" << endl;
    if (ptr == 0)
      return;
    free (ptr);
  }
};
int
main ()
{
  int *p1 = new int (3);
  cout << "p1=" << (void *)p1 << ", *p1=" << *p1 << endl;
  delete p1;

  girl *p2 = new girl (3, 8);
  delete (p2);
}