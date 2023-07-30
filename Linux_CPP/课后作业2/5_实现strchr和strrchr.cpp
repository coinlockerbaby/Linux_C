#include <iostream>
#include <string.h>

using namespace std;

// 返回在字符串s中第一次出现c的位置，如果找不到，返回0
const char *
mystrchr (const char *s, int c)
{
  char *p = (char *)s; // 用于遍历数组的指针
  while (*p)
    {
      if (*p == c)
        return p;
      p++;
    }
  return 0;
}

// 返回在字符串s中最后一次出现c的位置，如果找不到，返回0
const char *
mystrrchr (const char *s, const int c)
{
  char *p = (char *)s; // 用于遍历数组的指针
  char *p1 = 0;
  while (*p)
    {
      if (*p == c)
        p1 = p;
      p++;
    }
  return p1;
}
auto
main () -> int
{
  char ch[31] = { "hello worldh" };
  cout << (void *)ch << endl;
  cout << (void *)(mystrrchr (ch, 'h')) << endl;
}