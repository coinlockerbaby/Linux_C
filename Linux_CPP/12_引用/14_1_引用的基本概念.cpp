#include <iostream>
using namespace std;

int main() {
  int a = 3;
  int &ra = a;
  cout << "a的地址是:" << &a << "   a的值是" << a << endl;
  cout << "ra的地址是:" << &ra << " ra的值是" << ra << endl;
}
