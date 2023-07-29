#include <cstdlib>
#include <iostream>
#include <string.h>
using namespace std;

typedef struct {
  char name[21];
  int age;
  double weight;
  char sex;
  bool yz;
} st_girl;

int main() {
  st_girl grils[3];
  memset(grils, 0, sizeof(grils));
  grils[1] = {"lihua", 12, 12, 'x', 1};
  cout << "name " << grils[1].name << "\n"
       << "age " << grils[1].age << endl;
  exit(0);
}
