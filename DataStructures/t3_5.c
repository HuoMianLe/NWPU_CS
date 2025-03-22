// 循环右移
/*
任务描述
编写程序，将一维数组 A（下标从 1 开始）中的元素循环右移 k
位，要求只用一个元素大小的附加存储。

编程要求
根据提示，在右侧编辑器补充代码，完成数组的循环右移。

测试说明
输入说明：
第一行输入一维数组 A 的长度 n 和循环位移位数k (0<n<100;0<k<100)，用空格分开。
第二行输入 n 个元素。

输出说明：
输出循环右移 k 位后的一维数组。

平台会对你编写的代码进行测试：

测试输入：
6 3
1 2 3 4 5 6
预期输出：
4 5 6 1 2 3
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
  int elenum, mov;
  scanf("%d%d", &elenum, &mov);
  getchar();
  int rear = elenum + 1;
  int arr[rear];
  for (int i = 1; i < rear; i++) {
    scanf("%d", &arr[i]);
  }
  getchar();
  for (int i = 0; i < mov; i++) {
    arr[0] = arr[elenum];
    for (int j = elenum; j > 0; j--) {
      arr[j] = arr[j - 1];
    }
  }

  for (int i = 1; i < rear; i++) {
    printf("%d", arr[i]);
    if (i < elenum) printf(" ");
  }

  return 0;
}
