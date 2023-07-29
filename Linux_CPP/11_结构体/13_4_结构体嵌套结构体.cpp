#include <iostream>

using namespace std;

typedef struct {
  char name[21]; // 宠物名称
  char type[21]; // 宠物物种
} pet;

typedef struct {
  char name[21]; // 超女名称
  int age;       // 超女年龄
  pet pets;      // 宠物结构体
} st_girl;

int main() {
  st_girl girls = {"lihua", 12, {"huanhuan", 'x'}};
  cout << "girl name " << girls.name << "\n"
       << "girls pet name " << girls.pets.name << "\n"
       << "girls pet type " << girls.pets.type << endl;
}
