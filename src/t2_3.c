// 顺序表的删除
/*
任务描述
已知 A , B 和 C 为三个非递减有序的线性表，现要求对 A 表作如下操作：删去那些既在
B 表中出现又在 C 表中出现的元素。试对顺序表编写实现上述操作的算法。

编程要求
根据提示，在右侧编辑器补充代码，完成顺序表的删除操作。

测试说明
输入说明：第一行输入 3 个正整数 m,n,p
(m,n,p<=100)，用空格分开，分别表示三个线性表中的元素个数，其后 3 行依次输入
A,B,C 表中的元素。

输出说明：输出实现上述操作后的A表。

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

int *generateSeqList(int len) {
  int *seq_list = (int *)malloc(sizeof(int) * len);
  for (int i = 0; i < len; i++) {
    scanf("%d", &seq_list[i]);
  }
  return seq_list;
}

void Delete(int A[], int *a, int tmp, int *index) {
  for (int i = *index; i < *a; i++) {
    if (A[i] < tmp) {
      continue;
    }
    if (A[i] == tmp) {
      *index = i;
      for (int j = i + 1; j < *a; j++) A[j - 1] = A[j];
      *a = *a - 1;
      break;
    }
    if (A[i] > tmp) break;
  }
}

void findAndDelete(int A[], int B[], int C[], int *a, int b, int c,
                   int *index) {
  int b_i = 0;
  int c_i = 0;
  int tmp = 0;

  while (b_i < b && c_i < c) {
    while (B[b_i] < C[c_i]) b_i += 1;
    if (B[b_i] == C[c_i]) {
      tmp = B[b_i];
      Delete(A, a, tmp, index);
    }
    c_i += 1;
  }
}

int main() {
  int index = 0;
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  int *A = generateSeqList(a);
  int *B = generateSeqList(b);
  int *C = generateSeqList(c);
  // 确保C是长度较长的顺序表
  if (b > c) {
    int *arr = B;
    B = C;
    C = arr;
    int len = b;
    b = c;
    c = len;
  }
  findAndDelete(A, B, C, &a, b, c, &index);
  for (int i = 0; i < a; i++) {
    printf("%d", A[i]);
    if (i < a - 1) printf(" ");
  }
  return 0;
}
