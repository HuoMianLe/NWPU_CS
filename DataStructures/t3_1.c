// 表达式括号匹配
/*
任务描述
假设一个算术表达式中可以包含三种括号：圆括号“（”和“）”、方括号“[”和“]”和花括号“{”和“}”，
且这三种括号可按任意的次序嵌套使用（如：…[…{…}…[…]…]…[…]…(…)…）。
编写判别给定表达式中所含括号是否正确配对出现的程序（已知表达式已存入数据元素为字符的顺序表中）。

编程要求
根据提示，在右侧编辑器补充代码，完成表达式括号匹配。

测试说明
输入说明：输入算术表达式，换行结束。

输出说明：若给定表达式中所含括号正确配对，则输出 yes，否则输出 no。

平台会对你编写的代码进行测试：

测试输入：[5+(6-3)]-(2+3)]
预期输出：no
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct SqStk {
  int top;
  char str[1009];
} sqstk, *psqstk;

psqstk InitSqStk() {
  psqstk ptr = (psqstk)malloc(sizeof(sqstk));
  ptr->top = -1;
  return ptr;
}

void PushSqStk(psqstk sq_stk, char ch) { sq_stk->str[++sq_stk->top] = ch; }

void PopSqStk(psqstk sq_stk) { sq_stk->str[sq_stk->top--] = '\0'; }

int main() {
  char str[1009];
  fgets(str, sizeof(str), stdin);
  psqstk sq_stk = InitSqStk();
  char ch = '\0';
  for (int i = 0; str[i] != '\0'; i++) {
    ch = str[i];
    switch (ch) {
      case '{':
      case '[':
      case '(': {
        PushSqStk(sq_stk, ch);
        break;
      }

      case '}': {
        if (sq_stk->top != -1 && sq_stk->str[sq_stk->top] == '{') {
          PopSqStk(sq_stk);
          break;
        } else {
          printf("no");
          return 0;
        }
      }

      case ']': {
        if (sq_stk->top != -1 && sq_stk->str[sq_stk->top] == '[') {
          PopSqStk(sq_stk);
          break;
        } else {
          printf("no");
          return 0;
        }
      }

      case ')': {
        if (sq_stk->top != -1 && sq_stk->str[sq_stk->top] == '(') {
          PopSqStk(sq_stk);
          break;
        } else {
          printf("no");
          return 0;
        }
      }

      default:
        break;
    }
  }

  if (sq_stk->top == -1) {
    printf("yes");
  } else {
    printf("no");
  }
  free(sq_stk);
  return 0;
}
