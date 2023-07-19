#include <stdio.h>
#include <stdlib.h>

#define NAMESIZE 32

struct birthday_st
{
  int year;
  int month;
  int day;
};

struct student_st
{
  int id;
  char name[NAMESIZE];
  int math;
  int chinese;
  struct birthday_st birth;
};

int
main(void)
{
  struct student_st student = {.id = 123, .name = "李华", .math = 20};
  struct student_st *p = &student;
  printf("%d %s %d\n",student.id, student.name, student.math);
  printf("%d %s %d\n",p->id, p->name, p->math);
  exit(0);
}
