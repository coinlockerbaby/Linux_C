#include <iostream>
using namespace std;
int main() {
  char name[10] = {0};
  for (int i = 0; i < 10; i++)
    cout << "name[" << i << "] = " << (int)name[i] << endl;
}
