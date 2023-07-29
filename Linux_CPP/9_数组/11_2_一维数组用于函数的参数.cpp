#include <iostream>

using namespace std;

// 在函数中传入数组必须把数组的长度也传进来，因为函数中只能传入数组的指针
void func(int arr[], int len) {
  for (int i = 0; i < len; i++) {
    cout << "arr[" << i << "] 的值是" << arr[i] << endl;
  }
}

int main() {
  int a[] = {1, 2, 3, 4, 5, 6, 7};
  func(a, sizeof(a) / sizeof(int));
}
