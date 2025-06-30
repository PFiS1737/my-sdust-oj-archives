// Description
// 定义类MyString，由长度不超过100的字符串组成。重载其下标运算符：
// int operator[](char ch)
// 用于**重复**求指定字符ch在串中的下标。
// 重载其输入运算符，用于输入字符串。
//
// Input
// 输入一个不含空白符的字符串（长度不超过100个）和一个字符。
//
// Output
// 指定字符在字符串中的所有位置。

// Sample Input
// babababaab a

// Sample Output
// 1
// 3
// 5
// 7
// 8
// -1

#include <cstring>
#include <iostream>
using namespace std;

struct MyString {
  char str[100];
  int i;

  MyString() : i(0) {
    str[0] = '\0';
  }

  MyString(const char *s) : i(0) {
    strcpy(str, s);
  }

  int operator[](char c) {
    while (str[i] != '\0') {
      if (str[i++] == c) {
        return i - 1;
      }
    }
    return -1;
  }

  friend istream &operator>>(istream &is, MyString &s) {
    char tmp[100];
    cin >> tmp;
    s = MyString(tmp);
    return is;
  }
};

// Append Code
int main() {
  MyString mystr;
  char c;
  int pos;
  cin >> mystr >> c;
  do {
    pos = mystr[c];
    cout << pos << endl;
  } while (pos != -1);
  return 0;
}
