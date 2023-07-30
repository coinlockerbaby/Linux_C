// 实现strcat()和strncat()函数
#include <iostream>
#include <string.h>
using namespace std;

char*
mystrcat (char *dest, const char *src)
{
  memcpy(dest+strlen(dest),src,strlen(src)+1);
  return dest;  
}

char*
mystrncat(char* dest,const char* src,size_t n)
{
  memcpy(dest+strlen(dest),src,n);
  *(dest+strlen(dest)+n) = 0;
  return dest;
}

auto
main () -> int
{
  char str[31];
  memset(str,0,sizeof(str));
  cout << mystrncat(str,"hello",2);
}