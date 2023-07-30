// BF算法

// 返回子串substr在目标串str中第一次出现的位置，如果找不到，返回0。
#include <iostream>
#include <string.h>
using namespace std;

const char *
mystrstr (const char *str, const char *substr)
{
  size_t ii = 0, jj = 0;
  size_t len = strlen (str), slen = strlen (substr);
  while ((ii < len) && (jj < slen))
    {
      if (str[ii] == substr[jj]) // 目标串和子串字符相同，继续往下比对
        {
          ii++;
          jj++;
        }
      else // 目标串和子串字符不同，目标串下标退回第一个相同字符位置(ii-jj)，字串下标清零(jj=0),目标串往后一个位置(ii++)
        {
          ii = ii - jj;
          jj = 0;
          ii++;
        }
    }
  if(jj==slen)
    return str+(ii-jj);
  else
    return 0;
}

auto
main () -> int
{
  char str1[31] = {"helloworld"};
  char str2[31] = {"wol"};
  cout << (void*)(mystrstr(str1,str2)) <<endl;
}