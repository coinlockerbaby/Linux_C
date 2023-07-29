#include <cstdlib>
#include <iostream>

void func(int **p) { *p = new int(3); }

int main(int argc, char *argv[]) {
  int *p = nullptr;
  func(&p);
  std::cout << "**p =" << *p << std::endl;
  delete p;
  exit(0);
}
