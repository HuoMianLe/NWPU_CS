// 循环队列
/*
任务描述
假设将循环队列定义为：以域变量 rear 和 length
分别指示循环队列中队尾元素的位置和内含元素的个数。编写相应的入队列和出队列的程序。入队列时判断循环队列是否队满（在出队列的算法中要返回队头元素）。队满时，停止入队，队满时输出
yes ，否则输出 no 。

编程要求
根据提示，在右侧编辑器补充代码，完成循环队列的操作。

测试说明
输入说明：第一行输入队列大小 N
，第二行开始输入若干入队元素，第三行输入出队元素。

输出说明：第一行输出入队后队列情况，队满时输出 yes，否则输出
no。第二行输出出队操作后的循环队列。第三行输出出队后的队头元素。

平台会对你编写的代码进行测试：

测试输入：
5
3 4 6 2 7
4
预期输出：
yes
6 2 7
6
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
  int elenum = 0;
  scanf("%d", &elenum);
  getchar();
  char queue[elenum];
  int rear = 0;
  char ch = '\0';
  while ((ch = getchar()) != '\n')
    if (ch != 0x20) queue[rear++] = ch;
  int length = rear--;
  char target = '\0';
  scanf("%c", &target);
  getchar();
  if (length == elenum)
    printf("yes\n");
  else
    printf("no\n");
  int leader = 0;
  for (int i = 0; i < length; i++) {
    if (queue[i] == target) {
      leader = ++i;
      while (i < length) {
        printf("%c", queue[i]);
        if (++i < length) printf(" ");
      }
      printf("\n");
      break;
    }
  }
  printf("%c", queue[leader]);
  return 0;
}
