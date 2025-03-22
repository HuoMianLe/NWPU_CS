// 顺序表的插入运算
/*
任务描述
已知顺序表 L 递增有序，编写程序，将 X
插入到线性表的适当位置上，以保持线性表的有序性。

编程要求
根据提示，在右侧编辑器补充代码，完成顺序表的插入操作。

测试说明
输入说明：
第一行输入顺序表元素个数elenum；(0<elenum<1000)
第二行输入顺序表 L ；
第三行输入插入值 X 。

输出说明：
输出插入 X 后的有序顺序表。

平台会对你编写的代码进行测试：

测试输入：
7
2 3 4 5 6 7 8
1
预期输出：
1 2 3 4 5 6 7 8
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
  int ele_num;
  scanf("%d", &ele_num);

  double* seq_list = (double*)malloc(sizeof(double) * (ele_num + 1));

  for (int i = 0; i < ele_num; i++) {
    scanf("%lf", &seq_list[i]);
  }

  double num;
  scanf("%lf", &num);

  int i = 0;
  while (i < ele_num && num > seq_list[i]) {
    i++;
  }

  for (int j = ele_num; j > i; j--) {
    seq_list[j] = seq_list[j - 1];
  }

  seq_list[i] = num;

  for (int j = 0; j <= ele_num; j++) {
    printf("%.0lf", seq_list[j]);
    if (j < ele_num) {
      printf(" ");
    }
  }
  free(seq_list);
  return 0;
}
