// k阶斐波那契数列
/*
任务描述
试利用循环队列编写 k 阶斐波那契数列中前 n+1 项
（f(0),f(1),…,f(n)）的程序，要求满足： f(n)<=max 而 f(n+1)>max，其中 max
为某个约定的常数。（注意：本题所用循环队列的容量仅为 k
，则在程序执行结束时，留在循环队列中的元素应是所求 k 阶斐波那契序列中的最后 k 项
f(n−k+1),…,f(n))。 k阶斐波那契数列

编程要求
根据提示，在右侧编辑器补充代码，实现 k 阶斐波那契数列。

测试说明
输入说明：输入常数max（0<max<10000），阶数k（1<k<100），用空格隔开。

输出说明：输出 k 阶斐波那契数列中的最后 k 项 f(n-k+1),…,f(n)。

平台会对你编写的代码进行测试：

测试输入：14 2
预期输出：8 13
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct LqNode {
  int data;
  struct LqNode *next;
} LqN, *pLqN;

void InitFSQ(pLqN *leader, pLqN *rear, int k) {
  pLqN tmp = (pLqN)malloc(sizeof(LqN));
  tmp->data = 0;
  tmp->next = NULL;
  *leader = tmp;
  *rear = tmp;
  for (int i = 1; i < k; i++) {
    tmp = (pLqN)malloc(sizeof(LqN));
    tmp->data = 1;
    tmp->next = NULL;
    (*rear)->next = tmp;
    *rear = tmp;
  }
}

void DeEnLQ(pLqN *leader, pLqN *rear, int next) {
  pLqN ptr = (pLqN)malloc(sizeof(LqN));
  ptr->data = next;
  ptr->next = NULL;
  pLqN tmp = *leader;
  *leader = (*leader)->next;
  free(tmp);
  (*rear)->next = ptr;
  *rear = ptr;
}

void printLQ(pLqN leader) {
  pLqN ptr = leader;
  while (ptr) {
    printf("%d", ptr->data);
    ptr = ptr->next;
    if (ptr) printf(" ");
  }
}

int main() {
  int max = 0;
  int k = 0;
  scanf("%d%d", &max, &k);
  getchar();
  pLqN leader = NULL;
  pLqN rear = NULL;
  InitFSQ(&leader, &rear, k);
  int next = k - 1;
  int dnext = 2 * next;
  DeEnLQ(&leader, &rear, next);
  if (next <= max && dnext > max) {
    printLQ(leader);
  }
  while (!(next <= max && dnext > max)) {
    next = dnext;
    dnext = 2 * next - leader->data;
    DeEnLQ(&leader, &rear, next);
    if (next <= max && dnext > max) {
      printLQ(leader);
    }
  }

  while (leader) {
    pLqN ptr = leader;
    leader = leader->next;
    free(ptr);
  }
  return 0;
}
