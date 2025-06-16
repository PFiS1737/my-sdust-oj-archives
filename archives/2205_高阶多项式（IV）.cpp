// Description
// 定义一个n阶多项式为：a0xn+a1xn-1+a2xn-2+...+an-2x2+an-1x+an。其中ai是系数，均为int类型内的整数。x是未知量，是一个double类型的实数。现在请定义Equation类来表示这个多项式。
// 1.重载的>>运算符，按照格式要求读取方程。
// 2. 重载的<<运算符：用于输出方程。输出时xn输出x^n，且要按照我们平时惯用的方式来输出。包括如下规则：
// （1）如果系数为0，则相应的项不输出。如果所有的系数为0，则只输出一个0。
// （2）如果系数为1或-1，则不输出系数，仅输出对应的x的幂。
// （3）一次项如果输出，不输出指数，即不输出x^1，而是x。
// （4）0阶多项式即只有一个常数的多项式。
// （5）按照从高阶到低阶的顺序输出。
// （6）输出方程前，先按照样例格式输出各个方程的阶数。其中阶数定义为第一个非0系数对应的阶，如果只有常数项，则为0阶。
//
// Input
// 输入有多行。
// 第一行N表示后面后N组测试用例。
// 每组测试用例包括2行。第1行n表示输入的系数的个数（不包括常数项），第2行输入n+1个int范围内的整数 ，是该多项式的系数，按照从高阶到低阶的顺序输入。
// 注意：每个测试用例的系数，可能前面若干个都是0，此时的阶数不等于n。
//
// Output
// 见样例。

// Sample Input
// 6
// 3
// 100 0 0 -1
// 3
// 100 -1 -1 -1
// 3
// -1 -1 -1 -1
// 3
// 0 0 0 -1
// 3
// 0 -1 0 0
// 3
// -100 0 0 -1

// Sample Output
// 3 order polynomial:100x^3-1
// 3 order polynomial:100x^3-x^2-x-1
// 3 order polynomial:-x^3-x^2-x-1
// 0 order polynomial:-1
// 2 order polynomial:-x^2
// 3 order polynomial:-100x^3-1

#include <iostream>
using namespace std;

struct Equation {
  int n;
  int *args;

  Equation() : n(0), args() {
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

  friend istream &operator>>(istream &os, Equation &e) {
    cin >> e.n;
    e.args = new int[e.n + 1];
    for (int i = 0; i <= e.n; i++) {
      cin >> e.args[i];
    }
    return os;
  }
  friend ostream &operator<<(ostream &os, Equation &e) {
    cout << e.p() << " order polynomial:";
    e.print();
    return os;
  }

  int p() {
    for (int i = 0; i <= n; i++) {
      if (args[i] != 0) {
        return n - i;
      }
    }
    return 0;
  }
};

// Append Code
int main()
{
    int n, i;
    cin>>n;
    for (i = 0; i < n; i++)
    {
        Equation eq;
        cin>>eq;
        cout<<eq;
    }
    return 0;
}
