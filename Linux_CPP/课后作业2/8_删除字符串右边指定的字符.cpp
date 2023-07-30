//删除字符串右边指定的字符
#include <iostream>
#include <string.h>
using namespace std;

void
deleterchr(char* str,const int cc=' ')
{
  char* p = str;
  char* piscc=0; //指向右边全是字符cc的第一个位置
  while(*p!=0)
    {
      if(*p!=cc)
        piscc = 0;
      if(*p==cc&&piscc==0)
        piscc=p;
      p++; 
    }
  if(piscc!=0)
    *piscc=0;
}


auto
main()->int
{
  char str[31];
  strcpy(str,"abcdeas aaaa aaa");
  deleterchr(str,'a');
  cout << str<< endl;
}