// Description
// 判断两个字符串是否相等。要求大小写字母不敏感，即同一个字母的大写和小写视作相同字符。
//
// Input
// 输入两行，每行是一个字符串，长度不超过100字符。
//
// Output
// 若两字符串相等，输出“yes”，否则输出“no”。

// Sample Input
// abCdeF
// aBcdEF

// Sample Output
// yes

#include <iostream>
using namespace std;

int main() {
  string str1, str2;
  cin >> str1 >> str2;
  if (str1.length() != str2.length()) {
    cout << "no" << endl;
    return 0;
  }
  for (unsigned i = 0; i < str1.length(); i++) {
    if (tolower(str1[i]) != tolower(str2[i])) {
      cout << "no" << endl;
      return 0;
    }
  }
  cout << "yes" << endl;
  return 0;
}
