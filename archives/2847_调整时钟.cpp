// Description
// 时钟每天在00:00:00～23:59:59的范围内显示，新的一天又从00:00:00开始。现在编写一个模拟时钟调整的程序：对时钟的当前时刻hh:mm:ss和调整秒数n，当n<0时为时钟向前调整，当n>0时为时钟向后调整，计算出调整后时钟的时刻。 
// ----------------------------------------------------------------------------- 
// 结合“Append Code”中的代码，定义结构体类型，并编写函数，使程序能编译并运行正确结果。
//
// Input
// 输入多组数据至EOF结束，每个文件最多不超过50个测试样例。每组数据为hh:mm:ss格式的时钟和一个调整秒数n，n是int范围内的整数。
//
// Output
// 输出每组数据的运算结果，按照hh:mm:ss格式，不足两位需补0。

// Sample Input
// 15:45:04 5
// 15:45:09 -5

// Sample Output
// 15:45:09
// 15:45:04

#include <cstdio>

struct clock {
  int h, m, s;
};

int get_clock(clock *ck, int *n) {
  return scanf("%d:%d:%d %d", &ck->h, &ck->m, &ck->s, n);
}

clock turn_clock(clock ck, int n) {
  if (n > 0) {
    for (int i = 0; i < n; i++) {
      ck.s++;
      if (ck.s == 60) {
        ck.s = 0;
        ck.m++;
        if (ck.m == 60) {
          ck.m = 0;
          ck.h++;
          if (ck.h == 24) {
            ck.h = 0;
          }
        }
      }
    }
  } else {
    for (int i = 0; i < -n; i++) {
      ck.s--;
      if (ck.s == -1) {
        ck.s = 59;
        ck.m--;
        if (ck.m == -1) {
          ck.m = 59;
          ck.h--;
          if (ck.h == -1) {
            ck.h = 23;
          }
        }
      }
    }
  }
  return ck;
}

void put_clock(clock ck) {
  printf("%02d:%02d:%02d\n", ck.h, ck.m, ck.s);
}

// Append Code Start
int main()
{
    int n;
    struct clock ck;
    while(get_clock(&ck, &n) != EOF)
        put_clock(turn_clock(ck, n));
    return 0;
}
// Append Code End
