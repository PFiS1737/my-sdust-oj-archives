// Description
// 求n的k次方。
//
// Input
// 输入两个整数，n和k。满足0<=n,k<16
//
// Output
// 输出n^k

// Sample Input
// 3 2

// Sample Output
// 9

#include <iostream>
using namespace std;

int main() {
  long long n, k;
  cin >> n >> k;
  long long ans = 1;
  while (k--) {
    ans *= n;
  }
  cout << ans << endl;
  return 0;
}
