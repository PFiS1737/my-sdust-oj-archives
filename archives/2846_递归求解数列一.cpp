// Description
// 有数列1、2、4、7、11、16……。其中，第n项与第n-1项之差比第n-1项与第n-2项之差大1。
//
// 现在请你用递归方法编程求解该数列的第n项。
// -----------------------------------------------------------------------------
// Invalid Word（禁用单词）错误：在解决这个题目时，某些关键词是不允许被使用的。如果提交的程序中包含了下列的关键词之一，就会产生这个错误。
// 被禁用的关键字：for, while, break。
//
// Input
// 输入一个整数n。满足1<=n<=100。
//
// Output
// 输出数列的第n项。

// Sample Input
// 7

// Sample Output
// 22

#include <iostream>
using namespace std;

int handle(int n, int ret, int i) {
  if (n == 0) {
    return ret;
  }
  return handle(n - 1, ret + i, i + 1);
}

int main() {
  int n;
  cin >> n;
  cout << handle(n, 1, 0) << endl;
  return 0;
}
