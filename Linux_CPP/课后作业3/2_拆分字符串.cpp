// 字符串"aa,bb,cc,dd"，中间用逗号分隔，把它拆分到字符串维数组中，拆分后有4个数据项，分别是
// "aa"、"bb"、"cc"、"dd"。
#include <iostream>
#include <ostream>
#include <string.h>
#include <type_traits>

using namespace std;

size_t
splitstr (const char *str, const char *splitstr, char values[][51])
{
  if (str == 0 || splitstr == 0)
    exit(1);
  size_t slen = strlen (splitstr);
  if (slen == 0)
    exit(1);
  size_t ii = 0;         // values数组中，有效数据项的个数
  char *p = (char *)str; // 待拆分内容的指针
  while (1)
    {
      char *p1 = strstr (p, splitstr); // 查找分隔符位置
      if (p1 != 0) // 如果找到分隔符 就把分隔符前面的数据拷贝到values数组中；
        {
          strncpy (values[ii++], p, p1 - p);
          p = p1+slen; // 拷贝完之后将p指针指到分隔符后面
        }
      else // 如果没有找到分隔符说明已经遍历到最后一个数据项
        {
          strcpy (values[ii++], p);
          break;
        }
    }
  return ii;
}
auto
main () -> int
{
  char str[31] = "hello,nihao,wochao,nima";
  char values[31][51];
  memset(values,0,sizeof(values));
  int ii = splitstr(str,",",values);
  for(int i=0;i<ii;i++)
    {
      cout << values[i] << endl;
    }
}