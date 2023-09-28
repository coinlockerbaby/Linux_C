#include <stdio.h>
#include <stdlib.h>



int
main ()
{
  unsigned int a = 0x12345678;
  char *p = &a;
  printf ("%x", &p);
}