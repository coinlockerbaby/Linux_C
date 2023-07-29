#include <cstdlib>
#include <iostream>
#include <new>

using namespace std;
// nothrow 的作用是当申请内存失败的时候返回空指针nullptr
int main() {
  int *arr = new (std::nothrow) int[8];
  if (arr == nullptr) {
    cout << "new error" << endl;
    exit(1);
  }
  for (int i = 0; i < 8; i++) {
    arr[i] = 100 + i;
    cout << "arr[" << i << "] = " << arr[i] << endl;
  }
  delete[] arr;
  exit(0);
}
