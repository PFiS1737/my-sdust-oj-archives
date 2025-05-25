// Description
// 循环节‌是一个数学术语，指的是在一个无限循环小数中重复出现的一组数字。具体来说，循环节是指无限小数的小数点后从某一位起向右进行到某一位置的一节数字循环出现，首尾衔接，这种小数称为循环小数，这一节数字称为循环节。
// 可以证明：所有的无理数都是无限不循环小数，所有的有理数都是有限小数或无限循环小数。将有效小数后补充无限个0也可以视作无限循环小数。
// 有理数皆可写作两数相除（分数）。现在的任务是给出两整数相除（a/b），让你写程序求出其循环节。
// 注意，循环节输出必须用小数点后第一组重复的部分。例如，1/7的循环节是142857，而不能是428571、285714……。
//
// Input
// 输入多组数据至EOF结束，每个输入文件不超过10个测试样例。
// 每组输入两个正整数a、b，至EOF结束。满足a,b<10000。
//
// Output
// 输出a/b的循环节。注意，循环节输出必须用小数点后第一组重复的部分

// Sample Input
// 5 4
// 1 3
// 1 7
// 1 12

// Sample Output
// 0
// 3
// 142857
// 3

#include <stdio.h>
#include <string.h>

int main() {
  int a, b;
  while (scanf("%d %d", &a, &b) == 2) {
    int rem_pos[10000]; // 记录某一余数第一次出现的位置
    memset(rem_pos, -1, sizeof(rem_pos));

    int digits[10000]; // 存储小数部分的数字

    int rem = a % b;
    int pos = 0;

    // 余数不是 0，且该余数还没有出现过
    while (rem != 0 && rem_pos[rem] == -1) {
      rem_pos[rem] = pos;
      rem *= 10;
      digits[pos++] = rem / b;
      rem %= b;
    }

    if (rem == 0) {
      // 有限小数
      printf("0\n");
    } else {
      // 循环节从 rem_pos[rem] 到 pos - 1
      int start = rem_pos[rem];
      for (int i = start; i < pos; ++i)
        printf("%d", digits[i]);
      printf("\n");
    }
  }
  return 0;
}
