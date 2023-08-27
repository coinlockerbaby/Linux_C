#include <stdio.h>

int
main ()
{
  FILE *fp;
  fp = fopen ("1.txt", "r");
  if (fp == NULL)
    printf ("open file failed!\n");
  else
    printf ("open file success!\n");
}