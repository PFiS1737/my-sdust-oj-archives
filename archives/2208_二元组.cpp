// escription
// 定义两个类模板Variable和Tuple，每个类模板都只有一个类型参数T。
// Variable只有1个T类型的属性value。
// 其默认构造函数初始化value为0，另有带参构造函数和setValue用于设置value的值，
// 函数getValue用于获得value的值，以及析构函数。
// Tuple是两个Variable<T>的对象的组合类模板。有两个带参构造函数：Tuple(T,T)和Tuple(Variable<T>, Variable<T>)，
// 一个getSum函数用于返回其两个属性的和，以及析构函数。
// 构造函数、析构函数都有输出，格式见样例。
//
// Input
// 输入8个数。前4个是int类型的整数，后4个为double类型的实数。
//
// Output
// 见样例。

// Sample Input
// 1 2 3 4
// 1.1 2.2 3.3 4.4

// Sample Output
// A variable 1 is created.
// A variable 2 is created.
// A variable 1.1 is created.
// A variable 2.2 is created.
// A variable 0 is created.
// A variable 0 is created.
// A tuple (3,4) is created.
// A variable 0 is created.
// A variable 0 is created.
// A tuple (1,2) is created.
// A variable 1 is erased.
// A variable 2 is erased.
// A variable 0 is created.
// A variable 0 is created.
// A tuple (3.3,4.4) is created.
// A variable 0 is created.
// A variable 0 is created.
// A tuple (1.1,2.2) is created.
// A variable 1.1 is erased.
// A variable 2.2 is erased.
// T1's sum is 7
// T2's sum is 3
// T3's sum is 7.7
// T4's sum is 3.3
// A tuple (1.1,2.2) is erased.
// A variable 2.2 is erased.
// A variable 1.1 is erased.
// A tuple (3.3,4.4) is erased.
// A variable 4.4 is erased.
// A variable 3.3 is erased.
// A tuple (1,2) is erased.
// A variable 2 is erased.
// A variable 1 is erased.
// A tuple (3,4) is erased.
// A variable 4 is erased.
// A variable 3 is erased.
// A variable 2.2 is erased.
// A variable 1.1 is erased.
// A variable 2 is erased.
// A variable 1 is erased.

#include <iostream>
using namespace std;
 
template <typename T> struct Variable {
  T v;
  Variable(T v = 0) : v(v) {
    cout << "A variable " << v << " is created." << endl;
  }
  void setValue(T v) {
    this->v = v;
  }
  T getValue() const {
    return v;
  }
  ~Variable() {
    cout << "A variable " << v << " is erased." << endl;
  }
  T operator+(const Variable<T> &other) const {
    return this->v + other.v;
  }
  friend ostream &operator<<(ostream &os, const Variable<T> &var) {
    os << var.v;
    return os;
  }
};
 
template <typename T> struct Tuple {
  Variable<T> fst, scd;
  Tuple(T f = 0, T s = 0) : fst(), scd() {
    // NOTE: 屎
    fst.v = f;
    scd.v = s;
    cout << "A tuple (" << f << "," << s << ") is created." << endl;
  }
  Tuple(Variable<T> f, Variable<T> s) : fst(), scd() {
    // NOTE: 屎
    fst.v = f.v;
    scd.v = s.v;
    cout << "A tuple (" << f << "," << s << ") is created." << endl;
  }
  T getSum() const {
    return fst + scd;
  }
  ~Tuple() {
    cout << "A tuple (" << fst << "," << scd << ") is erased." << endl;
  }
};
 
// Append Code
int main()
{
    int a, b, c, d;
    double e, f, g, h;
    cin>>a>>b>>c>>d;
    cin>>e>>f>>g>>h;
    Variable<int> V1(a), V2(b);
    Variable<double> V3(e), V4(f);
    Tuple<int> T1(c, d), T2(V1, V2);
    Tuple<double> T3(g, h), T4(V3, V4);
    cout<<"T1's sum is "<<T1.getSum()<<endl;
    cout<<"T2's sum is "<<T2.getSum()<<endl;
    cout<<"T3's sum is "<<T3.getSum()<<endl;
    cout<<"T4's sum is "<<T4.getSum()<<endl;
    return 0;
}
