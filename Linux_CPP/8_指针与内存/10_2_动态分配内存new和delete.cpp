#include <cstdlib>
#include <iostream>
using namespace std;
// 动态分配的内存是在堆上创建的
int main(int argc, char *argv[]) {
  int *p = new int(5); // 括号里面的值是对申请的内存空间进行初始化
  cout << "*p =" << *p << endl;
  delete p;
  exit(0);
}
