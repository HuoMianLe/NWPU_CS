// 单链表的删除
/*
任务描述
已知 A , B 和 C 为三个非递减有序的线性表，均以单链表作为存储结构。现要求对 A
表作如下操作：删去那些既在 B 表中出现又在 C
表中出现的元素。试对单链表编写实现上述操作的算法，并释放 A 表中的无用结点空间。

编程要求
根据提示，在右侧编辑器补充代码，完成单链表的删除操作。

测试说明
输入说明：
第一行输入 3 个正整数m, n, p
(m,n,p<=100)，用空格分开，表示三个线性表中的元素个数，其后 3
行依次输入A,B,C表中的元素。

输出说明：
输出实现上述操作后的 A 表。

平台会对你编写的代码进行测试：

测试输入：
8 5 6
1 2 3 4 5 6 6 7
2 3 5 9 12
2 4 5 6 12 13
预期输出：
1 3 4 6 6 7
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int num;
  struct Node* next;
} Node, *pNode;

pNode initLinkList(int len) {
  pNode head = (pNode)malloc(sizeof(Node));
  head->num = 0;
  head->next = NULL;
  pNode tail = head;
  pNode tmp = NULL;
  for (int i = 0; i < len; i++) {
    tmp = (pNode)malloc(sizeof(Node));
    scanf("%d", &tmp->num);
    tmp->next = NULL;
    tail->next = tmp;
    tail = tmp;
  }
  return head;
}

void delA(pNode ptr) {
  pNode tmp = ptr->next;
  ptr->next = tmp->next;
  free(tmp);
}

void printA(pNode A) {
  pNode ptr = A;
  while (ptr->next) {
    ptr = ptr->next;
    printf("%d", ptr->num);
    if (ptr->next) {
      printf(" ");
    }
  }
}

void searchA(pNode ptr, int elenum) {
  while (ptr && ptr->next) {
    if (ptr->next->num == elenum) {
      delA(ptr);
    } else if (ptr->next->num < elenum) {
      ptr = ptr->next;
      searchA(ptr, elenum);
    } else {
      break;
    }
  }
}

void searchBC(pNode A, pNode B, pNode C, int b, int c) {
  pNode ptr = A;
  pNode psh = NULL;
  pNode plon = NULL;

  if (b >= c) {
    psh = C->next;
    plon = B->next;
  } else {
    psh = B->next;
    plon = C->next;
  }

  int tmp = 0;
  while (psh && plon) {
    if (psh->num < plon->num) {
      psh = psh->next;
    } else if (psh->num > plon->num) {
      plon = plon->next;
    } else {
      tmp = psh->num;
      psh = psh->next;
      plon = plon->next;
      searchA(ptr, tmp);
    }
  }
}

void freeLinkList(pNode head) {
  pNode ptr = head;
  pNode tmp = NULL;
  while (ptr) {
    tmp = ptr->next;
    free(ptr);
    ptr = tmp;
  }
}

int main() {
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  pNode A = initLinkList(a);
  pNode B = initLinkList(b);
  pNode C = initLinkList(c);
  searchBC(A, B, C, b, c);
  printA(A);

  freeLinkList(A);
  freeLinkList(B);
  freeLinkList(C);
  return 0;
}
