#include <iostream>

using namespace std;

void zs() { cout << "张三要先翻三个跟头再表白\n"; }

void ls() { cout << "李四要先吃饭再表白\n"; }

void show(void (*pf)()) {
  cout << "表白前\n";
  pf();
  cout << "表白后\n";
}

int main() { show(ls); }
