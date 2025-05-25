// Description
// 输入n个数，下标记为1～n。要求下标为奇数的数字按从小到大排序，下标为偶数的数字按从大到小排序。
//
// Input
// 输入不超过1000个整数至EOF结束。
//
// Output
// 输出排序后的整数。

// Sample Input
// 5 2 3 4  1 6 9 8 7 10

// Sample Output
// 1 10 3 8 5 6 7 4 9 2

#include <cstdio>
#include <cstdlib>

int cmp1(const void *a, const void *b) {
  return *(int *)a - *(int *)b;
}
int cmp2(const void *a, const void *b) {
  return *(int *)b - *(int *)a;
}

int main() {
  int a[1000], n = 0, b[1000], m = 0;
  int x, i = 0;
  while (scanf("%d", &x) != EOF) {
    if (++i % 2)
      a[n++] = x;
    else
      b[m++] = x;
  }
  qsort(a, n, sizeof(int), cmp1);
  qsort(b, m, sizeof(int), cmp2);

  printf("%d", a[0]);
  for (int j = 1; j < i; j++) {
    if (j % 2 == 0) {
      printf(" %d", a[j / 2]);
    } else {
      printf(" %d", b[j / 2]);
    }
  }

  return 0;
}
