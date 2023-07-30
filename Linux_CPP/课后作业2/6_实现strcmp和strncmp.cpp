#include <iostream>
#include <string.h>
using namespace std;

// strcmp
int
mystrcmp (const char *str1, const char *str2)
{
  size_t pos = 0;
  while (1)
    {
      if (str1[pos] > str2[pos])
        return 1;
      if (str1[pos] < str2[pos])
        return -1;
      if (str1[pos] == 0 && str2[pos] == 0)
        return 0;
      pos++;
    }
}

// strncmp
int
mystrncmp (const char *str1, const char *str2, size_t n)
{
  for (size_t pos = 0; pos < n; pos++)
    {
      if (str1[pos] > str2[pos])
        return 1;
      if (str1[pos] < str2[pos])
        return -1;
      if (str1[pos] == 0 && str2[pos] == 0)
        return 0;
    }
  return 0;
}

auto
main () -> int
{
  char str1[31] = { "hell" };
  char str2[31] = { "hello" };
  cout << mystrncmp (str1, str2,1) << endl;
}