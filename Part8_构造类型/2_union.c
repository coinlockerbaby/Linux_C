#include <stdio.h>
#include <stdlib.h>

union test_un {
  int i;
  float f;
  double d;
  char ch;
};

int main(void) {
  union test_un a;
  a.i = 1;
  printf("%d", a.i);
}
