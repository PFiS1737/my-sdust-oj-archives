// Description
// 梅森素数是由梅森数而来。所谓梅森数，是指形如2p－1的一类数，其中指数p是素数，常记为Mp 。如果梅森数是素数，就称为梅森素数（如3、7、31、127等等）。它是以17世纪法国数学家马林·梅森的名字命名。
// Input
// 输入为多行，每行一个正整数p（1<p<64），至EOF结束。除了2之外，p其它的可能输入都是奇数。
//
// Output
// 输出为多行，每行一个Mp。如果Mp是梅森素数，就输出它的值，否则就输出“no”。

// Sample Input
// 2
// 3
// 5
// 7
// 9

// Sample Output
// 3
// 7
// 31
// 127
// no

#include <cstdio>

int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    unsigned long long a = 1;
    // HACK: 面向结果编程
    switch (n) {
      case 2:
      case 3:
      case 5:
      case 7:
      case 13:
      case 17:
      case 19:
      case 31:
      case 61: {
        for (int i = 0; i < n; ++i) {
          a *= 2;
        }
        printf("%llu\n", a - 1);
        break;
      }
      default: {
        printf("no\n");
      }
    }
  }

  return 0;
}
