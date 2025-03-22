// 线性表的就地逆置
// 头插法创建单链表
/*
任务描述
试分别以不同的存储结构实现线性表的就地逆置算法，即在原表的存储空间将线性表(a1,
a2, … ,an) 逆置为(an, an−1, … , a1)
(1)以一维数组作存储结构。
(2)以单链表作存储结构。

输入说明：
第一行输入线性表元素个数elenum；(0 < elenum < 1000)
第二行输入elenum个数，作为线性表中的元素(a1, a2, … , an)

输出说明：
分两行分别输出要求（1）和要求（2）的线性表逆置结果(an, an−1, … , a1)
测试输入： 5
          2 5 3 7 15
预期输出： 15 7 3 5 2
          15 7 3 5 2
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* next;
} Node, *LinkList;

LinkList generateLinkList(int data[], int len) {
  LinkList head = (LinkList)malloc(sizeof(Node));
  head->next = NULL;
  LinkList tmp = NULL;
  LinkList tail = head;
  for (int i = 0; i < len; i++) {
    tmp = (LinkList)malloc(sizeof(Node));
    tmp->data = data[i];
    tmp->next = NULL;
    tail->next = tmp;
    tail = tmp;
  }
  return head;
}

void reverseLinkList(LinkList L) {
  LinkList front = NULL;
  LinkList current = L->next;
  LinkList next = NULL;
  while (current) {
    next = current->next;
    current->next = front;
    front = current;
    current = next;
  }
  L->next = front;
}

void printLinkList(LinkList L) {
  LinkList tmp = L->next;
  while (tmp) {
    printf("%d", tmp->data);
    tmp = tmp->next;
    if (tmp) printf(" ");
  }
}

void freeLinkList(LinkList L) {
  LinkList p, q;
  p = L;
  q = p->next;
  while (p) {
    free(p);
    p = q;
    q = p->next;
  }
}

void reverseSeqList(int data[], int len) {
  for (int i = 0, j = len - 1; i < j; i++, j--) {
    int tmp;
    tmp = data[i];
    data[i] = data[j];
    data[j] = tmp;
  }
}

void printSeqList(int data[], int len) {
  for (int i = 0; i < len; i++) {
    printf("%d", data[i]);
    if (i < len - 1) printf(" ");
  }
}

int main() {
  int elenum;
  scanf("%d", &elenum);

  int* seq_list = (int*)malloc(sizeof(int));

  for (int i = 0; i < elenum; i++) {
    scanf("%d", &seq_list[i]);
  }

  LinkList L = generateLinkList(seq_list, elenum);

  reverseSeqList(seq_list, elenum);
  reverseLinkList(L);

  printSeqList(seq_list, elenum);
  printf("\n");
  printLinkList(L);
  freeLinkList(L);
  free(seq_list);

  return 0;
}
