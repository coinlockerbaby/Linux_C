//删除字符串左边指定的字符 
#include <iostream>
#include <string.h>
using namespace std;

void deletelchr(char* str, const int cc = ' ')
{
  if(str==0)
    return;
  char* p = str;
  while(*p==cc)
    p++;
  memmove(str,p,strlen(str)-(p-str)+1);
  // memcpy()没有考虑内存重叠的情况，如果内存有重叠需要使用memmove();
}


auto
main()->int
{
  char str[31] = "hello";
  deletelchr(str,'h');
  cout << str <<endl;
}