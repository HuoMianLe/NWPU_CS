// LOCATE操作
/*
任务描述
设有一个双向循环链表，每个结点中除有 pre，data 和 next
三个域外，还增设了一个访问频度域 freq 。在链表被起用之前，频度域 freq
的值均初始化为零，而每当对链表进行一次
LOCATE（L,x）的操作后，被访问的结点（即元素值等于 x 的结点）中的频度域 freq
的值便增
1，同时调整链表中结点之间的次序，使其按访问频度非递增的次序排列，以便始终保持被频繁访问的结点总是靠近表头结点。试编写符合上述要求的
LOCATE 操作的程序。

编程要求
根据提示，在右侧编辑器补充代码，完成 LOCATE 操作。

测试说明
输入说明：
第一行输入双向循环链表的节点数 m 和被访问的节点数 n，
第二行输入双向循环链表各节点的值，
第三行依次输入被访问的节点。

输出说明：
输出符合上述要求的双向循环链表。
输出经过n次LOCATE后的链表。

平台会对你编写的代码进行测试：

测试输入：
7 1
a b c d e f g
d
预期输出：
d a b c e f g
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct dNode {
  int elenum;
  char data;
  int freq;
  struct dNode *pre;
  struct dNode *next;
} dNode, *pdNode;

pdNode createDL(int elenum) {
  pdNode head = (pdNode)malloc(sizeof(dNode));
  head->elenum = elenum;
  head->pre = head;
  head->next = head;
  head->data = '\0';

  pdNode tail = head;
  pdNode tmp = NULL;
  for (int i = 0; i < elenum; i++) {
    tmp = (pdNode)malloc(sizeof(dNode));
    getchar();
    scanf("%c", &tmp->data);
    tmp->elenum = 0;
    tmp->freq = 0;
    tail->next = tmp;
    tmp->pre = tail;
    tmp->next = head;
    head->pre = tmp;
    tail = tmp;
  }
  return head;
}

int compareDNode(pdNode p1, pdNode p2) {
  if (p1->freq > p2->freq)
    return 1;
  else
    return 0;
}

void sortDL(pdNode head, pdNode targetNode) {
  if (targetNode == head->next) return;

  pdNode insertPos = targetNode->pre;
  while (insertPos != head && compareDNode(targetNode, insertPos)) {
    insertPos = insertPos->pre;
  }
  targetNode->pre->next = targetNode->next;
  targetNode->next->pre = targetNode->pre;

  targetNode->next = insertPos->next;
  insertPos->next->pre = targetNode;
  targetNode->pre = insertPos;
  insertPos->next = targetNode;
}

void searchElement(pdNode head, char target) {
  pdNode ptr = head;
  int elenum = ptr->elenum;
  for (int i = 0; i < elenum; i++) {
    ptr = ptr->next;
    if (ptr->data == target) {
      ptr->freq += 1;
    }
    sortDL(head, ptr);
  }
}

void printDL(pdNode head) {
  pdNode ptr = head;
  int elenum = ptr->elenum;
  for (int i = 0; i < elenum; i++) {
    ptr = ptr->next;
    printf("%c", ptr->data);
    if (i < elenum - 1) printf(" ");
  }
}

int main() {
  int elenum, visitnum;
  scanf("%d%d", &elenum, &visitnum);

  pdNode DL = createDL(elenum);

  char target = '\0';
  for (int i = 0; i < visitnum; i++) {
    getchar();
    scanf("%c", &target);
    searchElement(DL, target);
  }

  printDL(DL);

  pdNode ptr = DL->next;
  for (int i = 0; i < elenum; i++) {
    pdNode tmp = ptr;
    ptr = ptr->next;
    free(tmp);
  }
  free(DL);
  return 0;
}
