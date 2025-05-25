// Description
// 给出2个有重复元素的、非递减排序的数组，求它们合并后的结果数组，结果数组中没有重复元素，且按照递增序排列。请定义如下函数实现上述功能：
// （1）int input(int a[])：读取一个数组a，返回值为读取的数组的元素的个数。
// （2）void output(int a[], int n)：输出具有n个元素的数组a。输出时两两元素之间用1个空格隔开。
// （3）int merge(int m, int a[], int n, int b[], int c[])：将具有m个数组a、具有n个元素的数组b，根据要求合并到数组c中，并返回数组c中元素的个数。
//
// Input
// 2个非递减排序的、含有重复元素的数组。每个数组占1行。每行的输入至少包含1个非零值，且以0作为输入结束标记（0不是数组元素）。
//
// Output
// 输入的两个数组合并且删除重复元素之后的数组，两两之间用1个空格隔开。

// Sample Input
// 1 1 2 2 3 3 0
// 2 2 4 4 5 5 5 5 0

// Sample Output
// 1 2 3 4 5

#include <algorithm>
#include <iostream>
using namespace std;

#define push(A, i) \
  do { \
    if (k == 0 || C[k - 1] != A[i]) { \
      C[k++] = A[i]; \
    } \
    i++; \
  } while (0)

// FIXME: 考虑输入 101 个数，最后一个是 0，这是符合输入要求的，
//        但你把他读到 A[101] 里了，导致溢出
// int input(int *A) {
//   int i = 0, n;
//   while (cin >> A[i] && A[i] != 0)
//     i++;
//   return i;
// }

int input(int *A) {
  int i = 0, n;
  while (cin >> n) {
    if (!n)
      break;

    A[i++] = n;
  }
  return i;
}

void output(int *C, int k) {
  for (int i = 0; i < k; i++) {
    cout << (i ? " " : "") << C[i];
  }
  cout << endl;
}

int merge(int m, int *A, int n, int *B, int *C) {
  // int i = 0, j = 0, k = 0;
  // while (i < m && j < n) {
  //   if (A[i] < B[j]) {
  //     push(A, i);
  //   } else if (A[i] > B[j]) {
  //     push(B, j);
  //   } else {
  //     push(A, i);
  //     j++;
  //   }
  // }
  // while (i < m) {
  //   push(A, i);
  // }
  // while (j < n) {
  //   push(B, j);
  // }
  // return k;

  return unique(C, merge(A, A + m, B, B + n, C)) - C;
}

// Append Code Start
int main() {
  int A[100], B[100], C[200];
  int m, n, k;
  m = input(A);
  n = input(B);
  k = merge(m, A, n, B, C);
  output(C, k);
  return 0;
}
// Append Code End
