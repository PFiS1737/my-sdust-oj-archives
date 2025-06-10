// Description
// 对于给定的一个数组，将下标为偶数的数组元素按照从大到小的顺序排序，将下标为奇数的数组元素按照从小到大的顺序排序。
// 根据题目要求和给定的main函数，编写Solve类，该类至少有如下成员函数：
// 1. void input()：输入一个数组。
// 2. void sort()：按照要求对数组进行排序。
// 3. void output()：按照要求输出数组。
//
// Input
// 输入有两行，第1行是一个正整数N，表示数组长度为N。第2行是N个整数，是数组元素。
//
// Output
// 排序后的结果。两两之间用1个空格隔开。

// Sample Input
// 9
// 10 6 7 3 2 13 6 23 236

// Sample Output
// 236 3 10 6 7 13 6 23 2

#include <algorithm>
#include <iostream>
using namespace std;

struct Solve {
  int n;

  int a[10000], i; // 下标为偶数，降序
  int b[10000], j; // 下标为奇数，升序

  void input() {
    cin >> n;
    i = j = 0;
    int x;
    for (int k = 0; k < n; k++) {
      cin >> x;
      if (k % 2 == 0)
        a[i++] = x;
      else
        b[j++] = x;
    }
  }

  void sort() {
    ::sort(a, a + i, greater<int>());
    ::sort(b, b + j, less<int>());
  }

  void output() {
    cout << a[0];
    for (int k = 1; k < n; k++) {
      if (k % 2 == 0) {
        cout << " " << a[k / 2];
      } else {
        cout << " " << b[k / 2];
      }
    }
  }
};

// Append Code
int main() {
  Solve solve;
  solve.input();
  solve.sort();
  solve.output();
  return 0;
}
