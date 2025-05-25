// Description
// 每本书都有国际标准书号（ISBN）。2007 年起，书号一般由 13 位数字组成，它们分成五个部分，用短横线隔开，如 978-7-111-33715-7，分别是前缀码、国别语种识别代号、出版社识别代号、书名版别代号，最后一位是校验码。现在给定书号，请你判断这本书是否为正版。
// 假设从左至右的各位数字依次为 a1,a2,...,a13，则最后一位校验码的计算方式如下：
// rem=[(a1+a3+a5+a7+a9+a11)+(a2+a4+a6+a8+a10+a12)x3] mod 10
// 如果rem为0则a13=0，否则a13=10-rem
//
// WARNING: 这个题内存就给了 1MB，用 iostream 都会爆
//
// Input
// 本题为多组数据，以EOF结尾。
// 每组数据输入一行，为一个格式形如 XXX-X-XXX-XXXXX-X或XXX-X-XXXX-XXXX-X或XXX-X-XX-XXXXXX-X 的字符串，表示书号。字符串中只会包含数字 0-9，以及短横线 -。
//
// Output
// 对于每组数据输出一行，若其校验码正确，输出 "YES"，否则输出 "NO"（不包括引号）。

// Sample Input
// 978-7-111-33715-7
// 978-7-121-39089-0
// 978-7-115-48666-1

// Sample Output
// YES
// YES
// NO

#include <cstdio>

int main() {
  char str[20];
  while (scanf("%s", str) != EOF) {
    int rem = 0;
    int k = 0;
    for (unsigned i = 0; i < 17; i++) {
      char ch = str[i];
      if (ch == '-')
        continue;
      rem += (++k % 2 == 0 ? 3 : 1) * (ch - '0');
      if (k == 12)
        break;
    }
    rem = rem % 10;
    int a13 = str[16] - '0';
    puts(((rem == 0 && a13 == 0) || (a13 == 10 - rem)) ? "YES" : "NO");
  }

  return 0;
}
