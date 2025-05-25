// Description
// 小明收到了秘密消息是一串字符。他知道这串字符里只有数字是有效的，而其它字符都是用来混淆的。所以他编写了一个程序来获取有效消息。
//
// Input
// 输入为一串字符，长度不超过100。
//
// Output
// 输出这串字符中的有效消息，如果消息全部是无效的，输出“null”。

// Sample Input
// ab1c24d

// Sample Output
// 124

#include <iostream>
using namespace std;

int main() {
  string str;
  cin >> str;
  bool flag = false;
  for (size_t i = 0; i < str.size(); i++) {
    if (str[i] >= '0' && str[i] <= '9') {
      cout << str[i];
      flag = true;
    }
  }
  cout << (flag ? "" : "null") << endl;
  return 0;
}
