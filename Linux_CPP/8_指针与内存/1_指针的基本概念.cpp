#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  int a;
  char b;
  bool c;
  string d;

  cout << "变量a的地址是:" << (void *)&a << endl;
  cout << "变量b的地址是:" << (void *)&b << endl;
  cout << "变量c的地址是:" << (void *)&c << endl;
  cout << "变量d的地址是:" << (void *)&d << endl;
}
