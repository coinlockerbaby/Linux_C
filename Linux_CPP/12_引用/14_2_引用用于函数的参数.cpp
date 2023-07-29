#include <iostream>

void func(int &a, int &b) {
  a = 4;
  b = 5;
}

int main() {
  int a = 1;
  int b = 2;
  func(a, b);
  std::cout << "a = " << a << std::endl;
  std::cout << "b = " << b << std::endl;
}
