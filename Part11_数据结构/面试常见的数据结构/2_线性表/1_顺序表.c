#include <stdio.h>
#include <stdlib.h>

typedef int E;

typedef struct
{
  E *array;
  int capacity;
  int size;
} ArrayList;
// 初始化顺序表
void
initList (ArrayList *list)
{
  list->array = malloc (sizeof (E) * 10);
  if (list->array == NULL)
    {
      fprintf (stderr, "init error\n");
      exit (-1);
    }
  list->capacity = 10;
  list->size = 0;
}

// 顺序表插入算法
void
insertList (ArrayList *list, E element, int index)
{
  // 判断输入可行性
  if ((index < 1) || (index > list->size + 1))
    {
      fprintf (stderr, "index input error\n");
      exit (-1);
    }
  // 动态扩展空间
  if (list->size == list->capacity)
    {
      E *tmp
          = malloc (list->capacity * sizeof (E)
                    + sizeof (E) * 10); // 申请一个比原来空间大10个单位的空间
      if (tmp == NULL)
        {
          fprintf (stderr, "malloc error\n");
        }
      for (int i = 0; i < list->size; i++)
        tmp[i] = list->array[i];
      free (list->array);
      list->array = tmp;
      list->capacity += 10; // 容量+=10
    }
  // 插入
  for (int i = list->size; i >= index; i--)
    list->array[i] = list->array[i - 1];
  list->array[index - 1] = element;
  list->size++;
}

// 顺序表删除算法
void
deleteList (ArrayList *list, int index)
{
  // 判断输入可行性
  if (index < 1 || index > list->size)
    {
      fprintf (stderr, "input error!\n");
      exit (-1);
    }
  for (int i = index - 1; i < list->size - 1; i++)
    {
      list->array[i] = list->array[i + 1];
    }
  list->size--;
}

// 获取长度
int
sizeList (ArrayList *list)
{
  return list->size;
}

// 获取指定位置的值的指针
E *
getList (ArrayList *list, int index)
{
  // 判断index的合法性
  if (index < 1 || index > list->size)
    {
      fprintf (stderr, "input error\n");
    }
  return &list->array[index - 1];
}

// 找到值相同的位序
int
findList (ArrayList *list, E element)
{
  for (int i = 0; i < list->size; i++)
    {
      if (list->array[i] == element)
        return i + 1;
    }
  return -1;
}

void
printList (ArrayList *list)
{
  for (int i = 0; i < list->size; i++)
    {
      printf ("%d ", list->array[i]);
    }
  printf ("\n");
}

int
main ()
{
  ArrayList list;
  initList (&list);
  for (int i = 1; i <= 30; i++)
    insertList (&list, i, i);
  deleteList (&list, 9);
  printf ("%d\n", findList (&list, 15));
  printf ("%d\n", *getList (&list, 3));
  printf ("%d\n", list.capacity);
  printList (&list);
}