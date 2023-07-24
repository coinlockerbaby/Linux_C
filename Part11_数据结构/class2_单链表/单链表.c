#include <stdio.h>
#include <stdlib.h>

// 定义链表结构体
typedef struct Node {
  int data;
  struct Node *next;
} node;

// 初始化链表函数
node *init_list(void) {
  node *list = malloc(sizeof(node));
  list->data = 0;
  list->next = NULL;
  return list;
}

// 头插式实现
void head_insert(node *list, int data) {
  node *nodehead = malloc(sizeof(node));
  nodehead->data = data;
  nodehead->next = list->next;
  list->next = nodehead;
  list->data++;
}

// 尾插实现
void tail_insert(node *list, int data) {
  node *nodetail = malloc(sizeof(node));
  nodetail->data = data;
  nodetail->next = NULL;
  list = list->next;
  while (list->next) {
    list = list->next;
  }
  list->next =
}

int main() {}
