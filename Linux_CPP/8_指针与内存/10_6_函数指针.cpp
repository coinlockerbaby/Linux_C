#include <iostream>

using namespace std;

void fun(int no, string str) { cout << "亲爱的" << no << "号" << str << endl; }

int main(int argc, char *argv[]) {
  int bh = 3;
  string message = "我是一只傻傻鸟";
  void (*p)(int, string);
  p = fun;
  fun(bh, message);
  exit(0);
}
