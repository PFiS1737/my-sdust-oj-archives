// Description
// 程序是由单词（Word）组成的，单词可以分为关键字、用户自定义标识符以及文字常量等。对于输入的不同字符串，编程判断属于哪一类单词。需要编写的类有：
// 1.Word类：用于描述单词的抽象类。成员函数isIllegal()是一个纯虚函数。
// 2.Keyword类：Word类的子类，用于判断一个字符串是否是关键字。成员函数getKeywords()用于读取所有的关键字。
// 3.UserDefined类：Word类的子类，用于判断一个字符串是否是合法的用户自定义标识符。
// 4.Integer类：Word类的子类，用于判断一个字符串是否是一个整型常量（不限制取值范围）。
//
// Input
// 输入有多行，第1行是一个正整数n，表示关键字个数。第2行是n个字符串，表示n个关键字。之后的若干行，每行包括1个字符和1个字符串，其中字符“k”表示后面要跟一个关键字，字符“u”表示后面要跟一个用户自定义标识符，字符“i”表示后面要跟一个整数。所有字符串都不含空白符。
//
// Output
// 除第1行和第2行输入外，其他每行输入对应1行输出。如果对应输入行的字符串属于相应字符表示的类型，则输出“Right.”，否则输出“Error.”。
//

// Sample Input
// 5
// int double float for if
// k int
// u int
// u Int
// i 321
// i -983
// i 143d

// Sample Output
// Right.
// Error.
// Right.
// Right.
// Right.
// Error.

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Word {
  string value;
  Word(string v) : value(v) {
  }
  virtual bool isIllegal() = 0;
  virtual ~Word() {
  }
};

struct Keyword : Word {
  static vector<string> keywords;

  Keyword(string v) : Word(v) {
  }

  bool isIllegal() {
    return find(keywords.begin(), keywords.end(), value) != keywords.end();
  }

  void getKeywords() {
    int n;
    cin >> n;
    string kw;
    for (int i = 0; i < n; ++i) {
      cin >> kw;
      keywords.push_back(kw);
    }
  }
};

vector<string> Keyword::keywords;

struct UserDefined : Word {
  UserDefined(string v) : Word(v) {
  }

  bool isIllegal() {
    if (Keyword(value).isIllegal())
      return false;
    if (!(isalpha(value[0]) || value[0] == '_'))
      return false;
    for (size_t i = 1; i < value.size(); i++) {
      char ch = value[i];
      if (!(isalnum(ch) || ch == '_'))
        return false;
    }
    return true;
  }
};

struct Integer : Word {
  Integer(string v) : Word(v) {
  }

  bool isIllegal() {
    if (value.empty())
      return false;
    size_t i = 0;
    if (value[0] == '-' || value[0] == '+') { // NOTE: 记得判断 + 号，否则 WA 67%
      if (value.size() == 1)
        return false;
      i++;
    }
    for (; i < value.size(); i++) {
      if (!isdigit(value[i]))
        break;
    }
    if (value[i] == '.')
      return false;
    string suffix = value.substr(i);
    if (!suffix.empty() && suffix != "u" && suffix != "l" && suffix != "ul" &&
        suffix != "U" && suffix != "L" && suffix != "UL" && suffix != "ull" &&
        suffix != "ULL") { // NOTE: 这些都可以没有
      if (suffix[0] == 'e' || suffix[0] == 'E') {
        if (suffix.size() == 1 ||
            (suffix[1] != '+' && suffix[1] != '-' && !isdigit(suffix[1])))
          return false;
        for (size_t j = 2; j < suffix.size(); j++) {
          if (!isdigit(suffix[j]))
            return false;
        }
      } else {
        return false;
      }
    }
    return true;
  }
};

// Append Code
// clang-format off
int main(){
    Word *word;
    char k;
    string str;
    Keyword keyword("");
    keyword.getKeywords();
    while(cin>>k>>str){
        switch(k){
        case 'k':
            word=new Keyword(str);
            break;
        case 'u':
            word=new UserDefined(str);
            break;
        case 'i':
            word=new Integer(str);
            break;
        }
        if (word->isIllegal())
            cout<<"Right."<<endl;
        else
            cout<<"Error."<<endl;
        delete word;
    }
    return 0;
}
