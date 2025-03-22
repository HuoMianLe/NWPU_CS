// 链表的归并
/*
任务描述
假设两个按元素值非递减有序排列的线性表 A 和 B
，均以单链表作为存储结构，试编写程序，将 A 表和 B
表归并成一个按元素值非递增有序排列的线性表 C ，并要求利用原表（即 A 表和 B
表的）结点空间存放表 C 。

编程要求
根据提示，在右侧编辑器补充代码，完成单链表的归并操作。

测试说明
输入说明：
第一行输入两个正整数m,n (m,n<=100),用空格分开，分别表示线性表 A 和 B
中元素个数，其后两行分别输入单链表 A 和 B 。

输出说明：
输出单链表 C 。

平台会对你编写的代码进行测试：

测试输入：
5 5
1 3 7 12 16
2 6 7 13 20
预期输出：
20 16 13 12 7 7 6 3 2 1
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* next;
} Node, *LinkList;

LinkList generateLinkList(int len) {
  int* data = (int*)malloc(sizeof(int) * len);
  for (int i = 0; i < len; i++) {
    scanf("%d", &data[i]);
  }
  LinkList L = (LinkList)malloc(sizeof(Node));
  L->next = NULL;
  LinkList tmp = NULL;
  for (int i = 0; i < len; i++) {
    tmp = (LinkList)malloc(sizeof(LinkList));
    tmp->data = data[i];
    tmp->next = L->next;
    L->next = tmp;
  }
  free(data);
  return L;
}

LinkList integrateLinkList(LinkList A, LinkList B) {
  LinkList C = (LinkList)malloc(sizeof(Node));
  C->next = NULL;
  LinkList tail = C;
  LinkList pA = A->next;
  LinkList pB = B->next;
  while (pA && pB) {
    LinkList tmp;
    if (pA->data > pB->data) {
      tmp = pA;
      pA = pA->next;
    } else {
      tmp = pB;
      pB = pB->next;
    }

    tail->next = tmp;
    tail = tmp;
  }

  LinkList remaining = pA ? pA : pB;
  while (remaining) {
    LinkList tmp = remaining;
    remaining = remaining->next;
    tail->next = tmp;
    tail = tmp;
  }

  free(A);
  free(B);
  return C;
}

void printLinkList(LinkList L) {
  LinkList ptr = L->next;
  while (ptr) {
    printf("%d", ptr->data);
    if (ptr->next) printf(" ");
    ptr = ptr->next;
  }
}

int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  LinkList A = generateLinkList(a);
  LinkList B = generateLinkList(b);
  LinkList C = integrateLinkList(A, B);
  printLinkList(C);
  return 0;
}
