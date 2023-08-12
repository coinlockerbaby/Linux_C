#include <stdio.h>
#include <stdlib.h>

typedef int E;

typedef struct Stack
{
  E *array;
  int capacity;
  int top; // 栈顶指针
} ArrayStack;

int
initStack (ArrayStack *stack)
{
  stack->array = malloc (sizeof (E) * 10);
  if (stack->array == NULL)
    return 0;
  stack->capacity = 10;
  stack->top = -1;
  return 1;
}

// 入栈
int
pushStack (ArrayStack *stack, E element)
{
  if (stack->top + 1 == stack->capacity) // 如果容量满了
    {
      int newCapacity = stack->capacity + 10; // 扩容10
      E *newArray
          = realloc (stack->array, newCapacity * sizeof (E)); // 重新申请空间
      if (newArray == NULL)
        return 0;
      stack->array = newArray;
      stack->capacity = newCapacity;
    }
  stack->array[++stack->top] = element;
  return 1;
}

// 判断栈是否为空
int
isEmpty (ArrayStack *stack)
{
  return stack->top == -1;
}

// 出栈
E
popStack (ArrayStack *stack)
{
  return stack->array[stack->top--];
}

void
printStack (ArrayStack *stack)
{
  printf ("|");
  for (int i = 0; i <= stack->top; i++)
    {
      printf ("%d, ", stack->array[i]);
    }
  printf ("\n");
}

int
main ()
{
  ArrayStack Stack;
  initStack (&Stack);
  for (int i = 0; i < 20; i++)
    {
      pushStack (&Stack, i * 10);
    }
  printStack (&Stack);
  while (!isEmpty (&Stack))
    {
      printf ("%d ", popStack (&Stack));
    }
}
