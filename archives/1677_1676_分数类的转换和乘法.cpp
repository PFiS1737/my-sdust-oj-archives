//
// Description
// 封装一个分数类Fract，用来处理分数功能和运算，支持以下操作：
// 1. 构造：传入两个参数n和m，表示n/m；分数在构造时立即转化成最简分数。
// 2. show()函数：分数输出为“a/b”或“-a/b”的形式，a、b都是无符号整数。若a为0或b为1，只输出符号和分子，不输出“/”和分母。
// 3. double类型转换函数：用分子除以分母，得到的小数。注意：分子为0时不要输出为“-0”
// 4. 在分数类上重载乘法运算符，进行分数的乘法运算
// -----------------------------------------------------------------------------
// 你设计一个Fract类，使得main()函数能够运行并得到正确的输出。调用格式见append.cc

// Sample Input
// 1 3 2 3
// 20 -15 150 80
// 0 77 -9 1
// 6 6 4 4
// 12 16 4 3
// -33 -48 6 11
// 0 -10 360 12

// Sample Output
// 0.222222 2/9
// -2.5 -5/2
// 0 0
// 1 1
// 1 1
// 0.375 3/8
// 0 0

#include <cstdlib>
#include <iostream>
using namespace std;

struct Fract {
  int n, m;
  bool neg;

  Fract(int n, int m) : neg(false) {
    int g = gcd(n, m);
    this->n = abs(n / g);
    this->m = abs(m / g);

    if (n * m < 0) {
      neg = n != 0;
    }
  }

  static int gcd(int a, int b) {
    while (b) {
      int t = b;
      b = a % b;
      a = t;
    }
    return a;
  }

  void show() const {
    if (neg) {
      cout << "-";
    }
    cout << n;
    if (m != 1) {
      cout << "/" << m;
    }
    cout << endl;
  }

  operator double() const {
    return (neg ? -1 : 1) * (double)n / m;
  }

  Fract operator*(const Fract &f) const {
    return Fract(((neg ^ f.neg) ? -1 : 1) * n * f.n, m * f.m);
  }
};

// Append Code
int main() {
  int n, m, p, q;
  while (cin >> n >> m >> q >> p) {
    Fract f1(n, m), f2(q, p);
    Fract fr = f1 * f2;
    cout << (double)fr << " ";
    fr.show();
  }
}
