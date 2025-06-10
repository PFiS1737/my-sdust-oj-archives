// Description
// 设a、b、c都是一位数，它们的组合abc和cba是两个三位数，对于给定的sum，输出满足和为sum的abc和cba，要求同一对数不重复输出。
// 根据题目要求和给定的main函数，编写相应的Solve类。
//
// Input
// 输入有若干行，每行一个整数。
//
// Output
// 每行输入对应一行输出，每行首先输出“Case # : ”，其中“#”为从1开始的测试用例编号。
// 然后输出对应测试用例的结果，每对数按照“abc-cba”的格式输出，如果有多对数满足条件，则按照第1个数从小到大的顺序输出，且两两之间用一个分号分开；
// 如果没有满足条件的解，则输出“No answer.”。

// Sample Input
// 111
// 222
// 333
// 444
// 555
// 666

// Sample Output
// Case 1 : No answer.
// Case 2 : 111-111
// Case 3 : No answer.
// Case 4 : 123-321;222-222
// Case 5 : No answer.
// Case 6 : 135-531;234-432;333-333

#include <cstdio>
#include <iostream>
using namespace std;

struct Solve {
  int num;
  Solve(int n) : num(n) {
  }

  int reverse(int n) {
    int ret = 0;
    while (n > 0) {
      ret = ret * 10 + n % 10;
      n /= 10;
    }
    return ret;
  }

  void printSolution() {
    bool is_first = true;
    for (int i = 101; i <= num / 2; i++) {
      if (i % 10 == 0)
        continue; // Skip numbers ending with 0
      int rev = reverse(i);
      if (i + rev == num) {
        if (is_first) {
          is_first = false;
        } else {
          cout << ";";
        }
        cout << i << "-" << rev;
      }
    }
    if (is_first)
      cout << "No answer.";
    cout << endl;
  }
};

// Append Code
int main() {
  int num, order = 0;
  while (scanf("%d", &num) != EOF) {
    Solve solve(num);
    printf("Case %d : ", ++order);
    solve.printSolution();
  }
  return 0;
}
