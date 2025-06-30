// HACK: pair 和 priority_queue 逃课
//
// Description
// 输入若干个学生的姓名和年龄，将他们排序后输出，并求输入的若干个学生的最大者。
// 定义一个类Student，拥有属性age（int类型）和name（字符串），重载其小于、输出和输入运算符。
// 小于运算符比较的规则是先比较年龄，年龄大的对象为大；如果年龄相同，则比较姓名，姓名大的对象为大。
// 基于Student类定义类StudentGroup，该类有若干个学生组成，定义其add方法、srt方法和show方法，
// 用于增加1个学生、对所有的学生排序和显示所有的学生信息。
//
// Input
// 输入有若干行，每行包括一个字符串（无空白符）、一个整数，分别学生的姓名name和年龄age。
//
// Output
// 先按照学生比较规则按照递增序输出所有学生信息，每个学生信息占一行。最后一行输出最大学生的信息，格式见样例。

// Sample Input
// Tom 19
// Jack 21
// Mary 20
// Tom 22
// Jack 13

// Sample Output
// Jack 13
// Tom 19
// Mary 20
// Jack 21
// Tom 22
// The max is Tom 22

#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, string> Student;

istream &operator>>(istream &is, Student &stu) {
  is >> stu.second >> stu.first;
  return is;
}
ostream &operator<<(ostream &os, const Student &stu) {
  os << stu.second << " " << stu.first;
  return os;
}

struct StudentGroup {
  priority_queue<Student, vector<Student>, greater<Student> > q;
  void add(const Student &stu) {
    q.push(stu);
  }
  void srt() {
  }
  void show() {
    while (!q.empty()) {
      cout << q.top() << endl;
      q.pop();
    }
  }
};

// Append Code
int main() {
  Student stu, max;
  StudentGroup stuG;
  while (cin >> stu) {
    if (!(stu < max))
      max = stu;
    stuG.add(stu);
  }
  stuG.srt();
  stuG.show();
  cout << "The max is " << max << endl;
  return 0;
}
