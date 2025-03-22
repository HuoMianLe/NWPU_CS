// 逆波兰式
/*
任务描述
假设表达式由单字母变量和双目四则运算算符构成。试编写程序，将一个通常书写形式且书写正确的表达式转换为逆波兰式。

编程要求
根据提示，在右侧编辑器补充代码，完成输出逆波兰式。

测试说明
输入说明：输入由单字母变量和双目四则运算算符构成的表达式。

输出说明：输出其逆波兰式。

平台会对你编写的代码进行测试：

测试输入：(a+b)*c
预期输出：ab+c*
*/

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char input[109] = "";
char ans[109] = "";

typedef struct Stk {
  char data[100];
  int top;
} Stk, *pStk;

pStk InitStk() {
  pStk ptr = (pStk)malloc(sizeof(Stk));
  ptr->top = -1;
  return ptr;
}

void PushStk(pStk ptr, const char ch) { ptr->data[++ptr->top] = ch; }

bool jdAccess(const pStk stk, const char ch) {
  if (stk->top == -1 || ch == '(')
    return true;  // 栈空或字符为'('，可以直接入栈
  if (stk->top > -1) {
    // 栈非空时的情况
    if (stk->data[stk->top] == '(') return true;  // 栈顶为'('时直接进栈
    if ((ch == '*' || ch == '/') &&
        (stk->data[stk->top] == '+' || stk->data[stk->top] == '-'))
      // 栈顶的优先级高于字符时可以入栈
      return true;
  }
  return false;
}

void ProcssInput(pStk stk) {
  char *ch = input;
  while (*ch) {
    if (*ch == '\n') break;
    // 字母可以直接进入ans（答案数列）
    else if (isalpha(*ch))
      strncat(ans, ch, 1);
    // 判断非字母是否可以直接进入ans
    else if (jdAccess(stk, *ch))
      PushStk(stk, *ch);
    else if (*ch == ')') {
      while (stk->data[stk->top] != '(') {
        strncat(ans, &stk->data[stk->top--], 1);
      }
      --stk->top;
    } else {
      while (stk->top != -1 && !jdAccess(stk, *ch)) {
        strncat(ans, &stk->data[stk->top--], 1);
      }
      PushStk(stk, *ch);
    }
    ++ch;
  }
  while (stk->top != -1) {
    strncat(ans, &stk->data[stk->top--], 1);
  }
}

int main() {
  fgets(input, sizeof(input), stdin);
  pStk stk = InitStk();
  ProcssInput(stk);
  printf("%s", ans);
  free(stk);
  return 0;
}
