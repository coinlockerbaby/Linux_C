// XML可扩展标记语言（eXtensible Markup Language）, 用于传输和存储数据。
// 例如：
// <bh>3</bh><name>西施</name><sex>女</sex><age>18</age><yz>漂亮</yz>
// 以上XML包含了以下数据项：
// 1）bh的值是3；
// 2）name的值是西施；
// 3）sex的值是女；
// 4）age的值是18；
// 5）yz的值是漂亮。
// 函数原型：
// // 解析xml字符串。
// // xmlbuffer：待解析的xml字符串。
// // fieldname：字段名。
// // value：字段的值。
// //
// ilen：字段值的最大长度，超出ilen的内容将会被丢弃，缺省取值0，表示不限长度。
// // 返回值：如果xmlbuffer中存在fieldname的数据项，返回true，否则返回false。
// // 注意，调用该函数的时候，必须保证value足够大，否则可能会造成内存泄漏。
// bool xmlbuffer(const char* xmlbuffer, const char* fieldname, char* value,
// const size_t ilen = 0);

#include <cstddef>
#include <iostream>
#include <string.h>
using namespace std;

bool
xmlbuffer (const char *xmlbuffer, const char *fieldname, char *value,
           const size_t ilen = 0)
{
  // 参数可行性验证
  if (xmlbuffer == 0 || fieldname == 0)
    return false;

  // 根据字段值生成xml标签 例如 "name" 生成 "<name>"和</name>
  size_t fieldnamelen = strlen (fieldname);
  char *sfieldname = new char[fieldnamelen + 3];
  char *efieldname = new char[fieldnamelen + 4];
  memset (sfieldname, 0, fieldnamelen + 3);
  memset (efieldname, 0, fieldnamelen + 4);
  strcpy (sfieldname, "<");
  strcat (sfieldname, fieldname);
  strcat (sfieldname, ">");
  strcpy (efieldname, "</");
  strcat (efieldname, fieldname);
  strcat (efieldname, ">");

  // 用strstr函数搜索xml字符串中出现 <label> 的位置
  const char *start = strstr (xmlbuffer, sfieldname);
  if (start == 0) // 如果没找到回收申请的空间然后返回错误
    {
      delete[] sfieldname;
      delete[] efieldname;
      return false;
    }
  // 用strstr函数搜索xml字符串中出现 </lable>的位置
  const char *end = strstr (xmlbuffer, efieldname);
  if (end == 0) // 如果没找到回收申请的空间然后返回错误
    {
      delete[] sfieldname;
      delete[] efieldname;
      return false;
    }

  size_t value_len = end - start - fieldnamelen - 2; // 计算字段值的长度

  // 从xml字符串中截取字段的值
  if (value_len < ilen || ilen == 0)
    {
      //<label>hello</label>
      strncpy (value, start + fieldnamelen + 2, value_len);
      value[value_len] = 0;
    }
  else
    {
      strncpy (value, start + fieldnamelen + 2, ilen);
      value[ilen] = 0;
    }
  // 字符提取完成，释放内存，返回正确
  delete[] sfieldname;
  delete[] efieldname;
  return true;
}

auto
main () -> int
{
  char xmlbuf[51] = { "<name>hana</name> <age>18</age>" };
  char value[31];
  memset (value, 0, sizeof (value));
  xmlbuffer (xmlbuf, "age", value);
  cout << value << endl;
}