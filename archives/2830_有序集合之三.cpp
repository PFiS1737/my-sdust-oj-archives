// Description
// 设计一个存储整数的有序集合类，其中的数据是按照从小到大的顺序存储的。
// 用C++编写OrdSet类来完成代码，调用格式见“Append Code”。
// OrdSet::input()按格式输入数据。
// OrdSet::output()按格式输出数据。
// OrdSet::is_equal ()判断参数与自身是否相等。
// OrdSet::is_equal ()判断参数是否为自身的子集。
// OrdSet::is_equal ()判断参数是否为自身的真子集。
// STL容器：set、map、vector、deque、queue、stack、array、list等被禁用。万能头文件被禁用
//
// Input
// 输入为两个集合：每个集合首先输入一个整数n（n>=0）。后接n个整数（有可能重复，重复的整数是集合中的同一个元素）。若n=0，则后续无输入。
//
// Output
// 输出用“[”和“]”包括起来有序集合的元素，按从小到大的顺序。例如：空集输出为“[NULL]”，只有一个元素0的集合输出为“[0]”。集合多个元素间用一个空格隔开。

// Sample Input
// 8
// 6 2 6 1 2 6 1 2
// 4
// 6 2 1 4

// Sample Output
// [1 2 6] is subset to [1 2 4 6].
// [1 2 6] is proper subset to [1 2 4 6].

#include <algorithm>
#include <iostream>
using namespace std;

struct OrdSet {
  int a[100];
  int n;

  void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a, a + n);
    n = unique(a, a + n) - a;
  }

  void output() const {
    cout << "[";
    if (n == 0)
      cout << "NULL";
    else {
      for (int i = 0; i < n; i++) {
        cout << a[i] << (i < n - 1 ? " " : "");
      }
    }
    cout << "]";
  }

  bool is_equal(const OrdSet &o) const {
    if (n != o.n)
      return false;
    for (int i = 0; i < n; i++) {
      if (a[i] != o.a[i])
        return false;
    }
    return true;
  }

  bool is_subset(const OrdSet &o) const {
    if (o.n > n)
      return false;
    for (int i = 0; i < n; i++) {
      if (find(a, a + n, o.a[i]) == a + n)
        return false;
    }
    return true;
  }

  bool is_proper_subset(const OrdSet &o) const {
    return is_subset(o) && !is_equal(o);
  }
};

// Append Code
void TestOrdSet(const OrdSet &lhs, const OrdSet &rhs)
{
    if(lhs.is_equal(rhs))
    {
        rhs.output();
        cout << " is equal to ";
        lhs.output();
        cout << "." << endl;
    }
    if(lhs.is_subset(rhs))
    {
        rhs.output();
        cout << " is subset to ";
        lhs.output();
        cout << "." << endl;
    }
    if(lhs.is_proper_subset(rhs))
    {
        rhs.output();
        cout << " is proper subset to ";
        lhs.output();
        cout << "." << endl;
    }
}
 
int main()
{
    OrdSet os, oo;
    os.input();
    oo.input();
    TestOrdSet(os, oo);
    TestOrdSet(oo, os);
    return 0;
}
