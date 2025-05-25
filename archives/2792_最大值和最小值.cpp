// Description
// 求多组整数的最大值和最小值。
//
// Input
// 输入为多行，每行为一组整数。每组整数以N开始，后接N个整数。当输入N为0时表示输入结束。
//
// Output
// 每组整数对应一行输出，是这组整数的最大值和最小值。

// Sample Input
// 3 1 2 3
// 5 10 15 20 30 50
// 0

// Sample Output
// 3 1
// 50 10

#include <climits>
#include <iostream>
using namespace std;

int main() {
  int n;
  while (cin >> n && n > 0) {
    int arr[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    int max = INT_MIN, min = INT_MAX;
    for (int i = 0; i < n; i++) {
      if (arr[i] > max) {
        max = arr[i];
      }
      if (arr[i] < min) {
        min = arr[i];
      }
    }
    cout << max << " " << min << endl;
  }
  return 0;
}
