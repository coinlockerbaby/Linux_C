// 实现strcpy()和strncpy()函数
#include <iostream>
#include <string.h>

using namespace std;
// 数组表示法
char *
mystrcpy1 (char *dest, const char *src)
{
  int ii = 0, jj = 0; // 目标字符串和源字符串的下表计数器
  while (src[jj])
    {
      dest[ii++] = src[jj++];
      dest[ii] = '\0';
    }
  return dest;
}
// 指针表示法
char *
mystrcpy2 (char *dest, const char *src)
{
  char* pdest = dest;
  char* psrc = (char*)src;
  while (*psrc)
      *pdest++ = *psrc++;
  *pdest = '\0';
  return dest;
}

// memcpy
char*
mystrcpy3(char* dest,const char* src)
{
  memcpy(dest,src,strlen(src)+1);
  return dest;
}

// strncpy
char*
mystrncpy(char* dest,const char* src,const size_t n)
{
  memcpy(dest,src,n);
  *(dest+n)=0;
  return dest;
}

auto
main () -> int
{
  char str1[51];
  memset (str1, 0, sizeof (str1));
  cout << mystrncpy(str1,"hello",5) << endl;
}