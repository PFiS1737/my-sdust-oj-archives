// Description
// 我们知道，C++中的整数类型，如short、int、long和long long等都有确定的表示范围，超大的整数是不能表示的。请定义一个类Decimal，用于表示大整数，并实现如下方法：
// 1.根据给出的main函数定义的构造函数。
// 2. 重载加法（“+”）运算符，可以实现一个Decimal对象与另一个Decimal对象求和、与一个int类型的数值求和。
// 3. 重载前缀自增运算符。
// 4. 重载下标运算符，用于求当前对象的指定下标位置的数字。
// 5. 重载输入、输出运算符。
//
// Input
// 输入3个数，前2个可能会超出unsigned long long的表示范围，最后1个是一个int类型的非负整数。
// 不考虑负数。
//
// Output
// 见样例。

// Sample Input
// 876543210012345678889
// 123456789987654321111
// 15

// Sample Output
// a = 876543210012345678889
// b = 123456789987654321111
// i = 15
// a = 876543210012345678890
// c = 1000000000000000000000
// d = 876543210012345678890
// e = 123456789987654321126
// f = 554433
// g = 12345
// 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

#include <iostream>
using namespace std;

struct Decimal {
  int digits[1000];
  int len;

  Decimal() : len(0) {
  }

  Decimal(int num) : len(0) {
    while (num) {
      digits[len++] = num % 10;
      num /= 10;
    }
  }

  Decimal(string str) : len(0) {
    for (int i = str.length() - 1; i >= 0; i--) {
      digits[len++] = str[i] - '0';
    }
  }

  int getLength() const {
    return len;
  }

  int operator[](int idx) const {
    return digits[len - 1 - idx];
  }

  Decimal operator+(const Decimal &o) const {
    Decimal res;
    int carry = 0;
    for (int i = 0; i < max(len, o.len) || carry; i++) {
      int sum = carry + (i < len ? digits[i] : 0) + (i < o.len ? o.digits[i] : 0);
      res.digits[res.len++] = sum % 10;
      carry = sum / 10;
    }
    return res;
  }

  Decimal &operator++() {
    *this = *this + Decimal(1);
    return *this;
  }

  friend istream &operator>>(istream &is, Decimal &d) {
    char str[1000];
    is >> str;
    d = Decimal(str);
    return is;
  }

  friend ostream &operator<<(ostream &os, const Decimal &d) {
    for (int i = d.len - 1; i >= 0; i--) {
      os << d.digits[i];
    }
    return os;
  }
};

// Append Code
int main() {
  Decimal a, b, c, d, e, f("554433"), g(12345);
  int i;
  cin >> a >> b >> i;
  cout << "a = " << a << endl;
  cout << "b = " << b << endl;
  cout << "i = " << i << endl;
  c = a + b;
  d = ++a;
  e = b + i;
  cout << "a = " << a << endl;
  cout << "c = " << c << endl;
  cout << "d = " << d << endl;
  cout << "e = " << e << endl;
  cout << "f = " << f << endl;
  cout << "g = " << g << endl;

  cout << c[0];
  for (i = 1; i < c.getLength(); i++) {
    cout << " " << c[i];
  }
  cout << endl;
  return 0;
}
