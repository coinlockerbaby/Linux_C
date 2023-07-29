#include <cstring>
#include <iostream>
#include <random>
using namespace std;

struct st_t {
  int a;
  int *p;
} stt;

int main() {
  stt.a = 3;
  stt.p = new int[100];
  cout << "调用前stt.a = " << stt.a << "\n"
       << "stt.p = " << stt.p << endl;
  memset(&stt, 0, sizeof(stt));
  cout << "调用后stt.a = " << stt.a << "\n"
       << "stt.p = " << stt.p << endl;
}
