#include <stdio.h>
#include <stdlib.h>

int
main ()
{
  int year, month, day;
  fscanf (stdin, "%d-%d-%d", &year, &month, &day);
  printf ("%d-%d-%d\n", year, month, day);
}