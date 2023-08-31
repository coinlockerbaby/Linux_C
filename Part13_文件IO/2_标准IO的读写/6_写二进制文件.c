#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
  char name[16];
  int age;
  char sex[8];
};

int
main ()
{
  FILE *fp;
  size_t ret;
  struct student stu;
  struct student stu2;
  memset (&stu, 0, sizeof (stu));

  fp = fopen ("1.bin", "w");
  if (fp == NULL)
    {
      perror ("fopen");
      goto end;
    }
  strcpy (stu.name, "zhangsan");
  strcpy (stu.sex, "male");
  stu.age = 18;
  ret = fwrite (&stu, sizeof (stu), 1, fp);
  if (ret == -1)
    {
      perror ("fwrite");
      goto end;
    }
  else
    {
      printf ("write student struct success!\n");
    }
  // fclose (fp);
  // fopen ("1.bin", "r");
  ret = fread (&stu2, sizeof (stu), 1, fp);
  if (ret == -1)
    {
      perror ("fread");
      goto end;
    }
  printf ("name = %s age = %d sex = %s\n", stu2.name, stu2.age, stu2.sex);

end:
  fclose (fp);
  return 0;
}