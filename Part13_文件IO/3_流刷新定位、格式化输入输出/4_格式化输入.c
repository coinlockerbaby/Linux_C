#include <stdio.h>
#include <stdlib.h>

int
main ()
{
  char *buf = malloc (128);
  int year = 2023;
  int month = 10;
  int day = 1;
  int syear, smonth, sday;
  sprintf (buf, "%d-%d-%d", year, month, day);
  printf ("%s\n", buf);
  sscanf (buf, "%d-%d-%d", &syear, &smonth, &sday);
  printf ("%d-%d-%d\n", syear, smonth, sday);
}