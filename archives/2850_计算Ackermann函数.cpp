// Description
// 阿克曼函数是非原始递归函数的例子；
// 它需要两个自然数作为输入值，输出一个自然数。它的输出值增长速度非常高。
// 1920年代后期，数学家David Hilbert的学生Gabriel Sudan和Wilhelm Ackermann，当时正研究计算的基础。
// Sudan发明了一个递归却非原始递归的Sudan函数。
// 1928年，阿克曼又独立想出了另一个递归却非原始递归的函数。
//
// 阿克曼（Ackermann）函数定义为：
//           ⎧ n + 1,                 if m = 0
// A(m, n) = ⎨ A(m − 1, 1),           if m > 0 and n = 0
//           ⎩ A(m − 1, A(m, n − 1)), if m > 0 and n > 0
//
/// 下面你编写一个程序来计算Ackermann函数的值。
//
// Input
// 输入为多组数据至EOF结束，每个输入文件不超过50个测试样例。每组两个正整数m、n。其中m <= 4、n和A(m, n) 均在int范围内且满足如下条件：
// 1. 当m < 2时，n 无其它限制；
// 2. 当m = 2时，n < 1e9；
// 3. 当m = 3时，n < 27；
// 4. 当m = 4时，n < 2；
//
// Output
// 输出A(m, n)的计算结果。

// Sample Input
// 0 1
// 1 1
// 2 2
// 3 4

// Sample Output
// 2
// 3
// 7
// 125

#include <cmath>
#include <iostream>
using namespace std;

int A(int m, int n) {
  switch (m) {
    // HACK: 面向结果编程
    case 0: {
      return n + 1;
    }
    case 1: {
      return n + 2;
    }
    case 2: {
      return 2 * n + 3;
    }
    case 3: {
      return pow(2, (n + 3)) - 3;
    }
    case 4: {
      if (n == 0)
        return 13; // 2^4 - 3
      else if (n == 1)
        return 65533; // 2^16 - 3
      else
        throw;
    }
    default: {
      throw;
    }
  }
}

int main() {
  int m, n;
  while (cin >> m >> n) {
    cout << A(m, n) << endl;
  }
  return 0;
}
