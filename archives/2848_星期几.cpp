// Description
// 对一个合法的日期，输出它是星期几的英文名称。
// 1、星期一：Monday
// 2、星期二：Tuesday
// 3、星期三：Wednesday
// 4、星期四：Thursday
// 5、星期五：Friday
// 6、星期六：Saturday
// 7、星期日：Sunday
//
// Input
// 输入为多组数据至EOF结束，每个文件最多不超过50个测试样例。每组输入三个整数表示日期的年月日，其中年份在1800-2400之间。输入的数据均为合法日期。
//
// Output
// 输出该日期是星期几。

// Sample Input
// 2025 1 10
// 2025 3 30

// Sample Output
// Friday
// Sunday

#include <cstdio>

int get_weekday(int y, int m, int d) {
  // INFO: 蔡勒公式
  if (m == 1 || m == 2) {
    m += 12; // 某年的 1、2 月要看作上一年的 13、14 月来计算
    y--;
  }
  int k = y % 100; // 年份前两位数
  int j = y / 100; // 年份后两位数
  int w = (d + 13 * (m + 1) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;
  return w;
}

const char *weekday_name(int w) {
  const char *names[] = {"Saturday",  "Sunday",   "Monday", "Tuesday",
                         "Wednesday", "Thursday", "Friday"};
  return names[w];
}

int main() {
  int y, m, d;
  while (scanf("%d %d %d", &y, &m, &d) == 3) {
    int w = get_weekday(y, m, d);
    printf("%s\n", weekday_name(w));
  }
  return 0;
}
