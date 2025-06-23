// Description
// 集合的运算就是用给定的集合去指定新的集合。设A和B是集合，则它们的并差交补集分别定义如下：
// A∪B={x|x∈A∨x∈B}
// A∩B={x|x∈A∧x∈B}
// A-B={x|x∈A∧x不属于 B}
// SA ={x|x∈(A∪B)∧x 不属于A}
// SB ={x|x∈(A∪B)∧x 不属于B}
//
// Input
// 第一行输入一个正整数T，表示总共有T组测试数据。（T<=200）
// 然后下面有2T行，每一行都有n+1个数字，其中第一个数字是n(0<=n<=100)，表示该行后面还有n个数字输入。
//
// Output
// 对于每组测试数据，首先输出测试数据序号，”Case #.NO”，
// 接下来输出共7行，每行都是一个集合，
// 前2行分别输出集合A、B，接下5行来分别输出集合A、B的并(A u B)、交(A n B)、差(A – B)、补。
// 集合中的元素用“{}”扩起来，且元素之间用“， ”隔开。

// Sample Input
// 1
// 4 1 2 3 1
// 0

// Sample Output
// Case# 1:
// A = {1, 2, 3}
// B = {}
// A u B = {1, 2, 3}
// A n B = {}
// A - B = {1, 2, 3}
// SA = {}
// SB = {1, 2, 3}

#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

void print_set(string name, set<int> s) {
  cout << name << " = {";
  for (set<int>::iterator it = s.begin(); it != s.end(); ++it) {
    cout << (it == s.begin() ? "" : ", ") << *it;
  }
  cout << "}" << endl;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    set<int> A, B;

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      A.insert(x);
    }

    cin >> n;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      B.insert(x);
    }

    set<int> U, I, D, SA, SB;

    set_union(A.begin(), A.end(), B.begin(), B.end(), inserter(U, U.begin()));
    set_intersection(A.begin(), A.end(), B.begin(), B.end(), inserter(I, I.begin()));
    set_difference(A.begin(), A.end(), B.begin(), B.end(), inserter(D, D.begin()));
    // SA = (A ∪ B) - A
    set_difference(U.begin(), U.end(), A.begin(), A.end(), inserter(SA, SA.begin()));
    // SB = (A ∪ B) - B
    set_difference(U.begin(), U.end(), B.begin(), B.end(), inserter(SB, SB.begin()));

    cout << "Case# " << t << ":" << endl;
    print_set("A", A);
    print_set("B", B);
    print_set("A u B", U);
    print_set("A n B", I);
    print_set("A - B", D);
    print_set("SA", SA);
    print_set("SB", SB);
  }

  return 0;
}
