#include <iostream>
#include <string.h>
using namespace std;

int main()
{
  int array[5] = {3, 6, 1, 2, 8};
  for (int i = 0; i < (sizeof(array) / sizeof(int)); i++)
  {
    cout << "array[" << i << "] = " << array[i] << endl;
  }
  cout << endl;
  //清空数组 memset
  memset(array, 0,sizeof(array));
  for (int i = 0; i < (sizeof(array) / sizeof(int)); i++)
  {
    cout << "array[" << i << "] = " << array[i] << endl;
  }
  cout <<endl;
  //复制数组 memcpy
  int array2[5] = {1,2,3,4,5};
  memcpy(array,array2,sizeof(array));
  for (int i = 0; i < (sizeof(array) / sizeof(int)); i++)
  {
    cout << "array[" << i << "] = " << array[i] << endl;
  }
  cout << endl;
  exit(0);
}
