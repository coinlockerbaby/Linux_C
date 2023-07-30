#include <iostream>
#include <string.h>
using namespace std;

void
deletestr (char *str, const char *substr)
{
  if(str==0||substr==0)  return;
  size_t slen = strlen(substr);
  if(slen==0) return;
  char *p = strstr(str,substr);
  if(p == 0)  return;
  size_t len = strlen(str);
  memmove(p,p+slen,len-(p-str)-slen+1);
}
auto
main () -> int
{
  char str[31];
  memset(str,0,sizeof(str));
  strcpy(str,"hello world");
  deletestr(str,"hello");
  cout << str<< endl;
}