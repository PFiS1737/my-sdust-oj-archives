// Description
// 定义一个类Equation，用来表示一个四阶多项式：a*x^4+b*x^3+c*x^2+d*x+e。其中a、b、c、d、e都是int类型的非负整数，是方程的系数。在该类中至少需要以下3个成员函数：
// 1. void Equation::print()：用来输出多项式。输出时，乘号（即*）不输出，幂用^表示，如x^5表示x的五次方。当所有的系数都为0时，输出0。如果只有部分系数为0，则这些为0的系数对应的项不输出。当系数为1时，系数不输出，如当a=1时，最高项应输出x^4，而不是1x^4。输出时，按照阶数从大到小依次输出。只要系数不为0，指数就输出，也就是说，x^1输出为x^1，而不是x。唯一的例外是常数项（即x^0）只需输出系数e（当e>0时）。
// 2. double Equation::getValue(double x)：x是给定的参数值，返回值是对应的多项式中当x取值为给定的参数时，多项式的值。
// 3. void Equation::setArgs(int a[])：a[]是五个元素的整数数组，该函数用于将五阶多项式的a、b、c、d、e分别设置为a[0]、a[1]、a[2]、a[3]和a[4]。
//
// Input
// 输入有2行。
// 第1行是五个int类型范围内的非负整数。
// 第2行是一个double类型的实数。
//
// Output
// 见样例。

// Sample Input
// 0 0 0 0 1
// 2

// Sample Output
// 1:0
// 2:x^4+2x^3+3x^1+2
// 40

#include <cmath>
#include <iostream>
using namespace std;

class Equation {
  int args[5];

public:
  Equation() {
    for (int i = 0; i < 5; i++) {
      args[i] = 0;
    }
  }
  void print() {
    bool is_first = true;

    for (int i = 0; i < 5; i++) {
      if (args[i] != 0) {
        if (!is_first) {
          cout << "+";
        }
        if (args[i] > 1 || i == 4)
          cout << args[i];
        if (i < 4)
          cout << "x^" << 4 - i;
        is_first = false;
      }
    }

    cout << (is_first ? "0" : "") << endl;
  }

  void setArgs(int a[5]) {
    for (int i = 0; i < 5; i++) {
      args[i] = a[i];
    }
  }

  double getValue(double x) {
    double result = 0;
    for (int i = 0; i < 5; i++) {
      result += args[i] * pow(x, 4 - i);
    }
    return result;
  }
};

// Append Code
int main()
{
    int i, a[5];
    double x;
    Equation eq1;
    cout<<"1:";
    eq1.print();
    for (i = 0; i < 5; i++)
        cin>>a[i];
    eq1.setArgs(a);
    cout<<"2:";
    eq1.print();
    cin>>x;
    cout<<eq1.getValue(x)<<endl;
    return 0;
}
