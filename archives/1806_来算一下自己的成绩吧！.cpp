// INFO: 💩
//
// Description
// OJ是一个同学们又爱又恨的东东。老师在OJ上布置了作业，并且把作业成绩作为实验课程的成绩。马上就要结课了，小明想知道自己到底能得到多少分，所以他向老师请教分数的计算方法。老师告诉他，分数是这么算滴：
// 1. 对于某次作业，假设所有同学中Accpted题目数最多为X，小明Accpted题目数为Y，那么这次作业小明得分100Y/X。
// 2. 如果小明不幸错过了某次作业或者没有题目被Accpted，那么为0分。
// 3. 最终成绩是所有作业成绩的平均分。
// 好了，小明从OJ上下载了所有的standing，发现要想计算成绩还是挺麻烦的。所以，他向你求助，请你帮忙编个程序，算算分数。
//
// Input
// 第1行N>0，表示本年级、本专业的学生数。
// 之后N行，每行是一个不含空白符的字符串，是一个学生的名字（假定没有重名，且姓名最多有10个字符）。
// 接着是M>0，表示老师总共布置的作业次数。
// 每次作业的输入中，第1行K>0，表示这次作业的standing中有提交记录的学生人数。之后K行是K个学生的姓名及其Accpted的题目数。
//
// Output
// 第1行输出：NAME        TEST1  TEST2  TEST3 ...... FINAL。
// 其中，“TEST？”的个数等于作业次数，按照顺序依次输出，如上所示。
// 之后根据输入的专业学生姓名顺序，依次输出所有学生的每次作业成绩以及最终成绩。
// 所有输出左对齐。
// 成绩保留2位小数，且左对齐输出。
// 输出的每一列的第1个字符要对齐。
// 见样例。

// Sample Input
// 5
// zhangsan
// lisi
// wangwu
// liuliu
// dingqi
// 3
// 2
// zhangsan 4
// lisi 8
// 5
// zhangsan 11
// lisi 7
// wangwu 4
// liuliu 3
// dingqi 4
// 3
// zhangsan 3
// lisi 10
// wangwu 7

// Sample Output
// NAME        TEST1  TEST2  TEST3  FINAL
// zhangsan    50.00  100.00 30.00  60.00 
// lisi        100.00 63.64  100.00 87.88 
// wangwu      0.00   36.36  70.00  35.45 
// liuliu      0.00   27.27  0.00   9.09  
// dingqi      0.00   36.36  0.00   12.12 

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> students(n);
  map<string, vector<double> > scores;

  for (int i = 0; i < n; ++i) {
    cin >> students[i];
    scores[students[i]] = vector<double>();
  }

  int m;
  cin >> m;

  for (int _ = 0; _ < m; ++_) {
    int k;
    cin >> k;
    map<string, int> acd;
    int acm = 0;

    for (int i = 0; i < k; ++i) {
      string name;
      int ac;
      cin >> name >> ac;
      acd[name] = ac;
      acm = max(acm, ac);
    }

    for (int i = 0; i < (int)students.size(); i++) {
      string s = students[i];
      if (acd.count(s)) {
        double score = acm == 0 ? 0.0 : 100.0 * acd[s] / acm;
        scores[s].push_back(score);
      } else {
        scores[s].push_back(0.0);
      }
    }
  }

  cout << left << setw(12) << "NAME";
  for (int i = 0; i < m; ++i) {
    cout << "TEST" << i + 1
         << (i + 1 >= 10 ? " " : "  "); // INFO:  死妈格式化，你他妈有本事开 C++11, 给我 to_string
  }
  cout << "FINAL" << endl;

  for (int i = 0; i < (int)students.size(); i++) {
    string s = students[i];
    cout << left << setw(12) << s;
    double total = 0.0;
    for (int j = 0; j < (int)scores[s].size(); j++) {
      double sc = scores[s][j];
      cout << fixed << setprecision(2) << left << setw(7) << sc;
      total += sc;
    }
    double avg = total / m;
    cout << fixed << setprecision(2) << left << setw(6) << avg << endl; // INFO: 6 : 666
  }

  return 0;
}
