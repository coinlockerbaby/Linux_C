#include <iostream>
#include <string.h>
using namespace std;

typedef struct st_person {
  char name[21];
  int age;
  double weight;
  char sex;
  bool yz;
} st_person;

int main() {
  st_person *st_p = new st_person;
  memset(st_p, 0, sizeof(st_person));
  cout << "name =" << st_p->name << endl;
  cout << "age =" << st_p->age << endl;
  cout << "weight =" << st_p->weight << endl;
  cout << "sex =" << st_p->sex << endl;
  cout << "yz =" << st_p->yz << endl;
  delete st_p;
}
