#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

class girl
{
public:
  int m_bh;            // 编号
  int m_xw;            // 胸围
  static char *m_pool; // 内存池指针
  /*******************[内存池管理初始化]*********************/
  static bool
  initpool ()
  {
    m_pool = (char *)malloc (18); // 向系统申请18字节的内存
    if (m_pool == 0)
      return false;         // 申请失败返回false
    memset (m_pool, 0, 18); // 把内存池初始化为0
    cout << "内存池的起始地址: " << (void *)m_pool << endl;
    return true;
  }
  static void
  freepool () // 释放内存池
  {
    if (freepool == 0)
      return;
    free (m_pool);
    cout << "内存池已释放" << endl;
  }
  /**********************[重载new和delete]***********************/
  // 向内存池申请内存
  void *
  operator new (size_t size)
  {
    if (m_pool[0] == 0) // 判断第一个位置是否空闲
      {
        cout << "分配了第一块内存: " << (void *)(m_pool + 1) << endl;
        m_pool[0] = 1; // 把第一个位置标记为已分配
        return m_pool + 1;
      }
    if (m_pool[9] == 0) // 判断第二个位置是否空闲
      {
        cout << "分配了第二块内存: " << (void *)(m_pool + 1) << endl;
        m_pool[9] = 0;
        return m_pool + 9;
      }
    // 如果都不可用，就向系统直接申请内存
    void *ptr = malloc (size);
    cout << "申请到的内存地址是: " << ptr << endl;
    return ptr;
  }
  // 释放向内存池申请的内存
  void
  operator delete (void *ptr)
  {
    if (ptr == 0) // 如果传入空指针 直接返回
      return;
    if (ptr == m_pool + 1)
      {
        cout << "释放了第一块内存" << endl;
        m_pool[0] = 0;
        return;
      }
    if (ptr == m_pool + 9)
      {
        cout << "释放了第二块内存" << endl;
        m_pool[9] = 0;
        return;
      }
    // 如果传入的地址不属于内存池，把他归还给系统
    free (ptr);
    return;
  }

  /******************[结构体构造与析构]*****************/
  girl (const int bh, const int xw) : m_bh (bh), m_xw (xw) { ; }
  ~girl () { cout << "调用了析构函数" << endl; }
};

char *girl::m_pool = 0;

int
main ()
{
  if (girl::initpool () == false)
    {
      cout << "初始化内存池失败" << endl;
      exit (-1);
    }
  girl *p1 = new girl (3, 8); // 使用内存池第一个位置
  cout << "p1的地址是: " << p1 << "编号: " << p1->m_bh
       << ", 胸围: " << p1->m_xw << endl;
  girl *p2 = new girl (3, 8); // 使用内存池第二个位置
  cout << "p2的地址是: " << p2 << "编号: " << p2->m_bh
       << ", 胸围: " << p2->m_xw << endl; // 使用
  girl *p3 = new girl (3, 8);             // 使用系统内存
  cout << "p3的地址是: " << p3 << "编号: " << p3->m_bh
       << ", 胸围: " << p3->m_xw << endl;
  delete p1;
  girl *p4 = new girl (3, 8); // 使用内存池第一个位置
  cout << "p4的地址是: " << p4 << "编号: " << p4->m_bh
       << ", 胸围: " << p4->m_xw << endl;
  delete p2; // 释放内存池第二个位置
  delete p3; // 释放系统内存
  delete p4; // 释放内存池第三个位置
  girl::freepool ();
}