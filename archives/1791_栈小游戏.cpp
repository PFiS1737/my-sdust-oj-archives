// INFO: 💩
//
// Description
// 小明想深入了解Stack（栈）的用法，所以他打算写一个类来模拟一下。但是他没有学过C++中强大的STL，所以他现在向你求助了。
// 请帮他编写一个类Operation，包括4个属性：
// 1. vector<int> data：存储用于仿真的数据。
// 2. stack<int> iStack：栈。
// 3. vector<char> opers：对栈的操作。
// 4. vector<int> result：存储出栈的数据。
// 还有4个方法：
// 1. void inputData()：读取数据。
// 2. void inputOpers()：读取操作。
// 3. void showResult()：显示出栈的数据序列。
// 4. void clearData()：清空所有的属性值。
//
// Input
// 第1行N>0表示有N个测试用例。
// 每个测试用例由两行组成：
// 1. 第1行是若干个int类型的数据，以“0”作为结束标识。
// 注意：“0”不作为输入数据即Operation类中data成员的一个元素，只是用做结束标识。
// 2. 第2行是若干个英文字母，用'i'或'I'（字母I，不是数字1.）表示入栈操作，用‘o'或者'O’（字母O，不是数字0.）表示出栈操作，
// 用'e'或者'E'表示输入结束。但是小明很不仔细，这些字符序列中可能包括其他字符。
//
// Output
// 输出有N行，每个测试用例产生一行输出。
// 每行的格式为：“The pop sequence is: ”，之后按照出栈顺序显示所有数据，这些数据两两之间用1个空格隔开，
// 且最后没有空格。如果没有产生出栈数据，则显示“Empty.”

// Sample Input
// 6
// 1 2 3 4 5 6 7 8 -1 -2 -3 -4 -5 -6 -7 0
// i I I I o O o c c c e
// 1 2 3 4 5 6 7 8 -1 -2 -3 -4 -5 -6 -7 0
// o o o i i i i o o i i o o o o o o o o o o o o e
// 1 2 3 4 5 6 7 8 -1 -2 -3 -4 -5 -6 -7 0
// c c c i c i i o o c c i i i i i i i i i i i o o o o o c e
// 1 2 3 4 5 6 7 8 -1 -2 -3 -4 -5 -6 -7 0
// i i i i i i i i i i i i i i i i i i i i i i i i i i o o o o o e
// 1 2 3 4 5 6 7 8 -1 -2 -3 -4 -5 -6 -7 0
// o o o o o o o c c c c c c c c e
// 1 2 3 4 5 6 7 8 -1 -2 -3 -4 -5 -6 -7 0
// i i i i i i i i i i i i i i e

// Sample Output
// The pop sequence is: 4 3 2
// The pop sequence is: 4 3 6 5 2 1
// The pop sequence is: 3 2 -6 -5 -4 -3 -2
// The pop sequence is: -7 -6 -5 -4 -3
// The pop sequence is: Empty.
// The pop sequence is: Empty.

#include <cstdio>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
 
using namespace std;
 
struct Operation {
  queue<int> data;
  stack<int> s;
  vector<int> result;
 
  void inputData() {
    int x;
    while (cin >> x && x != 0) {
      data.push(x);
    }
    getchar();
  }
 
  void inputOpers() {
    string line;
    getline(cin, line);
    for (size_t i = 0; i < line.size(); i++) {
      switch (line[i]) {
        case 'i':
        case 'I': {
          if (!data.empty()) {
            s.push(data.front());
            data.pop();
          }
          break;
        }
        case 'o':
        case 'O': {
          if (!s.empty()) {
            result.push_back(s.top());
            s.pop();
          }
          break;
        }
        case 'e':
        case 'E': {
          goto a;
        }
        default:
          break;
      }
    a: {}
    }
  }
 
  void showResult() {
    cout << "The pop sequence is:";
 
    if (result.empty()) {
      cout << " Empty.";
    } else {
      for (size_t i = 0; i < result.size(); ++i) {
        cout << " " << result[i];
      }
    }
 
    cout << endl;
  }
 
  void clearData() {
    while (!s.empty())
      s.pop();
    while (!data.empty())
      data.pop();
    result.clear();
  }
};
 
// Append Code
int main()
{
    Operation myOp;
    int cases;
    cin>>cases;
    for (int i = 0; i < cases; i++)
    {
        myOp.clearData();
        myOp.inputData();
        myOp.inputOpers();
        myOp.showResult();
    }
    return 0;
}
