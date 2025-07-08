// INFO: 💩
//
// Description
// 现在有一个多态问题，需要你用C++类的继承和多态来实现出来。
// 现在有A、B、C、D、E、F六个类，每个类比自己的父类（如果有的话）多存储一个int类型的成员变量，每个类都有一个print()函数用来输出对象存储的数据。
// 这六个类满足如下继承关系：A是B、C的父类，B是D、E的父类，C是F的父类。在析构函数里添加适当的代码产生符合对象删除次序的输出。
// 程序代码见“Append Code”。
//
// Input
// 先输入一个n，表示后面有n行数据，每行首先输入一个字符表示类名，然后输入三个整数，用于创建该类的对象。
//
// Output
// 输出对象中存储的数据。

// Sample Input
// 2
// B 20 30 40
// F 666 777 888

// Sample Output
// B : 20 30
// F : 666 777 888
// Delete B!
// Delete A!
// Delete F!
// Delete C!
// Delete A!

#include <iostream>
using namespace std;

struct A {
  int _a;
  A(int a) : _a(a) {
  }
  int a() {
    return _a;
  }
  virtual void print() {
    cout << "A : " << _a << endl;
  }
  virtual ~A() {
    cout << "Delete A!" << endl;
  }
};

struct B : virtual A {
  int _b;
  B(int a, int b) : A(a), _b(b) {
  }
  int b() {
    return _b;
  }
  void print() {
    cout << "B : " << _a << " " << _b << endl;
  }
  ~B() {
    cout << "Delete B!" << endl;
  }
};

struct C : virtual A {
  int _c;
  C(int a, int c) : A(a), _c(c) {
  }
  int c() {
    return _c;
  }
  void print() {
    cout << "C : " << _a << " " << _c << endl;
  }

  ~C() {
    cout << "Delete C!" << endl;
  }
};

struct D : B {
  int _d;
  D(int a, int b, int d) : A(a), B(a, b), _d(d) {
  }
  int d() {
    return _d;
  }
  void print() {
    cout << "D : " << _a << " " << _b << " " << _d << endl;
  }
  ~D() {
    cout << "Delete D!" << endl;
  }
};

struct E : B {
  int _e;
  E(int a, int b, int e) : A(a), B(a, b), _e(e) {
  }
  int e() {
    return _e;
  }
  void print() {
    cout << "E : " << _a << " " << _b << " " << _e << endl;
  }
  ~E() {
    cout << "Delete E!" << endl;
  }
};

struct F : C {
  int _f;
  F(int a, int c, int f) : A(a), C(a, c), _f(f) {
  }
  int f() {
    return _f;
  }
  void print() {
    cout << "F : " << _a << " " << _c << " " << _f << endl;
  }
  ~F() {
    cout << "Delete F!" << endl;
  }
};

// Append Code
int main() {
  A *p[10];
  int n, i;
  cin >> n;
  for (i = 0; i < n; i++) {
    char ch;
    cin >> ch;
    int x, y, z;
    cin >> x >> y >> z;
    if (ch == 'A')
      p[i] = new A(x);
    if (ch == 'B')
      p[i] = new B(x, y);
    if (ch == 'C')
      p[i] = new C(x, y);
    if (ch == 'D')
      p[i] = new D(x, y, z);
    if (ch == 'E')
      p[i] = new E(x, y, z);
    if (ch == 'F')
      p[i] = new F(x, y, z);
  }
  for (i = 0; i < n; i++)
    p[i]->print();
  for (i = 0; i < n; i++)
    delete p[i];
}
