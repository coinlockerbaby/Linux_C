#include <iostream>
using namespace std;

typedef struct {
  char name[21]; // 姓名
  int score[3];  // 用于存放三个评委打分
  int age;
  double weight;
  char sex;
  bool yz;
} st_girl;

int main() {
  st_girl girl;
  for (int i = 0; i < 3; i++) {
    girl.score[i] = 100 + i;
  }
  for (int i = 0; i < 3; i++) {
    cout << "girl score" << girl.score[i] << endl;
  }
}
