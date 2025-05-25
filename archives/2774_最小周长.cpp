// Description
// 一个矩形的面积为S，已知该矩形的边长都是整数，求所有满足条件的矩形中，周长的最小值。例如：S = 24，那么有{1 24} {2 12} {3 8} {4 6}这4种矩形，其中{4 6}的周长最小，为20。
//
// Input
// 输入1个整数S。
//
// Output
// 输出最小周长。

// Sample Input
// 24

// Sample Output
// 20

#include <iostream>
using namespace std;

int main() {
  int s;
  cin >> s;

  int min = __INT_MAX__;
  for (int a = 1; a * a <= s; a++) {
    int b = s / a;
    if (a * b != s) {
      continue;
    }
    int c = a + a + b + b;
    if (c < min) {
      min = c;
    }
  }

  cout << min << endl;

  return 0;
}
