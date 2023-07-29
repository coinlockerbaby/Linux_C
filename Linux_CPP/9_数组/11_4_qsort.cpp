#include <cstdlib>
#include <iostream>
using namespace std;
int compasc(const void *p1, const void *p2) {
  if ((*(int *)p1) < (*(int *)p2))
    return -1;
  if ((*(int *)p1) == (*(int *)p2))
    return 0;
  if ((*(int *)p1) > (*(int *)p2))
    return 1;
  else {
    exit(1);
  }
  // 以上判断等同于 *(int *)p1 - *(int *)p2
  // 如果想要从大到小排序只要把p2 和 p1调换位置即可
}

int compdesc(const void *p1, const void *p2) {
  return (*(int *)p2 - *(int *)p1);
}

int main() {
  int a[8] = {4, 2, 7, 5, 8, 6, 1, 3};
  qsort(a, sizeof(a) / sizeof(int), sizeof(int), compdesc);
  for (int i = 0; i < sizeof(a) / sizeof(int); i++) {
    cout << "a[" << i << "] = " << a[i] << endl;
  }
}
