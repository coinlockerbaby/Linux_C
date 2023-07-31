#include <iostream>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100 // 顺序表的最大长度

using namespace std;

typedef int ElemType; // 给数据元素的数据类型起别名
struct SeqList        // 静态顺序表的结构体
{
  ElemType data[MAXSIZE]; // 用静态数组存储循序表中的元素;
  size_t length;          // 顺序表的表长(有效元素的个数)
};

// 清空顺序表
void
ClearList (SeqList &LL)
{
  LL.length = 0;                               // 表长置零
  memset (&LL, 0, sizeof (SeqList) * MAXSIZE); // 清空数组
}

auto
main () -> int
{
}