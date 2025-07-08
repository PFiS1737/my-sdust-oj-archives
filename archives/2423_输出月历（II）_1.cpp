// Description
// 输出公元1900～2200年之间任意一月的月历。
//
// Input
// 输入若干行，至EOF结束，每行两个整数，分别表示年和月。
//
// Output
// 对应输入顺序输出月历，两个月历之间有一个空行。
// 每个月历的第一行为表头"Sun Mon Tue Wen Thu Fri Sat"，表示星期日～星期六。
// 第二行开始的每行为一个星期，把每月的1日～结尾一日对应阿拉伯数字填入其中。
// 每列占3个字符，其中的数字右对齐，每两列之间一个空格分隔，每行最后一个数字后面不要有空格。
// 最后一日后面不要有空格。

// Sample Input
// 2019 11
// 2019 12
// 2020 1
// 2020 2

// Sample Output
// Sun Mon Tue Wen Thu Fri Sat
//                       1   2
//   3   4   5   6   7   8   9
//  10  11  12  13  14  15  16
//  17  18  19  20  21  22  23
//  24  25  26  27  28  29  30
// 
// Sun Mon Tue Wen Thu Fri Sat
//   1   2   3   4   5   6   7
//   8   9  10  11  12  13  14
//  15  16  17  18  19  20  21
//  22  23  24  25  26  27  28
//  29  30  31
// 
// Sun Mon Tue Wen Thu Fri Sat
//               1   2   3   4
//   5   6   7   8   9  10  11
//  12  13  14  15  16  17  18
//  19  20  21  22  23  24  25
//  26  27  28  29  30  31
// 
// Sun Mon Tue Wen Thu Fri Sat
//                           1
//   2   3   4   5   6   7   8
//   9  10  11  12  13  14  15
//  16  17  18  19  20  21  22
//  23  24  25  26  27  28  29

#include <iomanip>
#include <iostream>
using namespace std;

int getDaysInMonth(int y, int m) {
  static int days_in_month[] = {
      -1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
  };

  if (m == 2 && ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))) {
    return 29;
  }

  return days_in_month[m];
}

// NOTE: 见 `./2848_星期几.cpp`
int getWeekday(int y, int m, int d) {
  if (m == 1 || m == 2) {
    m += 12;
    y--;
  }
  int k = y % 100;
  int j = y / 100;
  int w = (d + 13 * (m + 1) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;
  return (w + 7 - 1) % 7;
}

int main() {
  int y, m;
  int first = true;
  while (cin >> y >> m) {
    if (!first)
      cout << endl;

    first = false;

    cout << "Sun Mon Tue Wen Thu Fri Sat" << endl;

    int start = getWeekday(y, m, 1);
    for (int _ = 0; _ < start; _++) {
      cout << "    ";
    }

    int days = getDaysInMonth(y, m);
    for (int i = 1; i <= days; i++) {
      cout << setw(3) << i;
      if ((i + start) % 7 == 0 || i == days) {
        cout << endl;
      } else {
        cout << " ";
      }
    }
  }
}
