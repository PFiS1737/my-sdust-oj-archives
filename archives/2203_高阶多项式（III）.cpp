// Description
// 定义一个n阶多项式为：a0xn+a1xn-1+a2xn-2+...+an-2x2+an-1x+an。其中ai是系数，均为int类型内的整数。x是未知量，是一个double类型的实数。现在请定义Equation类来表示这个多项式。Equation类至少要有3个方法：
// 1. void Equation::setArgs(int a[], int n)：a是(n+1)个系数构成的数组，n是多项式的阶数。注意：系数个数比阶数多1。
// 2. void Equation::print()：用于输出方程。输出时xn输出x^n，且要按照我们平时惯用的方式来输出。包括如下规则：
// （1）如果系数为0，则相应的项不输出。如果所有的系数为0，则只输出一个0。
// （2）如果系数为1或-1，则不输出系数，仅输出对应的x的幂。
// （3）一次项如果输出，不输出指数，即不输出x^1，而是x。
// （4）0阶多项式即只有一个常数的多项式。
// （5）按照从高阶到低阶的顺序输出。
// 3. 重载的加法运算符，实现两个多项式相加，相加的结果需要合并同类项。
//
// Input
// 输入有4行。第1行、第3行是两个多项式的阶数，第2行、第4行是两个多项式的系数，按照从高阶到低阶的顺序输入。
//
// Output
// 见样例。

// Sample Input
// 4
// 1 2 3 4 5
// 4
// 5 4 3 2 1

// Sample Output
// x^4+2x^3+3x^2+4x+5
// 5x^4+4x^3+3x^2+2x+1
// 6x^4+6x^3+6x^2+6x+6

#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

struct Equation {
  int n;
  int *args;

  Equation() : args() {
  }
  Equation(Equation &o) : n(o.n), args(new int[n + 1]) {
    copy(o.args, o.args + n + 1, args);
  }

  void setArgs(int *a, int n) {
    this->n = n;
    this->args = new int[n + 1];
    copy(a, a + n + 1, args);
  }

  void print() {
    bool is_first = true;

    for (int i = 0; i <= this->n; i++) {
      if (args[i] == 0)
        continue;

      if (!is_first)
        cout << (args[i] > 0 ? "+" : "-");

      if (is_first && args[i] < 0)
        cout << "-";

      if (args[i] > 1 || i == this->n || args[i] < -1)
        cout << (args[i] > 0 ? args[i] : -args[i]);

      if (i < this->n) {
        int s = this->n - i;
        if (s > 1)
          cout << "x^" << s;
        else
          cout << "x";
      }

      is_first = false;
    }

    cout << (is_first ? "0" : "") << endl;
  }

  double getValue(double x) {
    double result = 0.0;

    for (int i = 0; i <= this->n; i++) {
      result += args[i] * pow(x, this->n - i);
    }

    return result;
  }

  Equation operator+(Equation &o) {
    if (n >= o.n) {
      Equation ret(*this);
      int offset = n - o.n;
      for (int i = 0; i <= o.n; i++) {
        ret.args[i + offset] += o.args[i];
      }
      return ret;
    } else {
      Equation ret(o);
      int offset = o.n - n;
      for (int i = 0; i <= n; i++) {
        ret.args[i + offset] += args[i];
      }
      return ret;
    }
  }
};

// Append Code
int main()
{
    int j, m, *a;
    Equation eq1, eq2;
    cin>>m;
    a = new int[m + 1];
    for (j = 0; j <= m; j++)
        cin>>a[j];
    eq1.setArgs(a, m);
    eq1.print();
    delete []a;
 
    cin>>m;
    a = new int[m + 1];
    for (j = 0; j <= m; j++)
        cin>>a[j];
    eq2.setArgs(a, m);
    eq2.print();
    delete[] a;
 
    (eq1 + eq2).print();
    return 0;
}
