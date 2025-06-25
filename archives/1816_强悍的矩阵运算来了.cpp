// INFO: 💩
//
// Description
// 定义一个Matrix类，用于存储一个矩阵。重载其+、*运算符，分别用于计算两个矩阵的和、乘积；
// 重载其<<和>>运算符，用于输出和输入一个矩阵。
// 要求当两个矩阵不能进行加法或乘法运算时，应该输出Error。
//
// Input
// 输入第1行N>0，表示有N组测试用例，共2N个矩阵。
// 每组测试用例包括2个矩阵。每个矩阵首先输入行数、列数，之后是该矩阵的所有元素。
//
// Output
// 每个测试用例产生一组输出。具体格式见样例。注意：当不能进行加法或乘法运算时，应输出Error。

// Sample Input
// 3
// 2 2
// 1 1
// 1 1
// 2 2
// 2 2
// 2 2
// 1 1
// 1
// 1 2
// 2 2
// 1 1
// 1
// 2 2
// 2 2
// 2 2

// Sample Output
// Case 1:
// 3 3
// 3 3
//
// 4 4
// 4 4
// Case 2:
// Error
//
// 2 2
// Case 3:
// Error
//
// Error

#include <iostream>
#include <vector>
using namespace std;

struct Matrix {
  vector<vector<int> > mt;
  bool err; // INFO: 我不知道是哪个没有双亲的人教的你在类型类里面做错误传递
            //       但这道题还必须这么做
  Matrix() : err(false) {
  }
  Matrix(int n, int m) : mt(n, vector<int>(m)), err(false) {
  }
  Matrix operator+(const Matrix &other) const {
    int n = mt.size(), m = mt[0].size();
    Matrix result(n, m);
    if (mt.size() != other.mt.size() || mt[0].size() != other.mt[0].size()) {
      result.err = true;
      return result;
    }
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        result.mt[i][j] = mt[i][j] + other.mt[i][j];
    return result;
  }
  Matrix operator*(const Matrix &other) const {
    int n = mt.size(), m = mt[0].size(), p = other.mt[0].size();
    Matrix result(n, p);
    if (m != (int)other.mt.size()) {
      result.err = true;
      return result;
    }
    for (int i = 0; i < n; i++)
      for (int j = 0; j < p; j++)
        for (int k = 0; k < m; k++)
          result.mt[i][j] += mt[i][k] * other.mt[k][j];
    return result;
  }
  friend istream &operator>>(istream &is, Matrix &matrix) {
    int n, m;
    is >> n >> m;
    matrix = Matrix(n, m);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        is >> matrix.mt[i][j];
    return is;
  }
  friend ostream &operator<<(ostream &os, const Matrix &matrix) {
    if (matrix.err) {
      os << "Error" << endl;
      return os;
    }
    int n = matrix.mt.size(), m = matrix.mt[0].size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        os << matrix.mt[i][j];
        if (j < m - 1)
          os << " ";
      }
      os << endl;
    }
    return os;
  }
};

// Append Code
int main() {
  int cases, i;
  cin >> cases;
  for (i = 0; i < cases; i++) {
    Matrix A, B, C, D;
    cin >> A >> B;
    C = A + B;
    D = A * B;
    cout << "Case " << i + 1 << ":" << endl;
    cout << C << endl;
    cout << D;
  }
  return 0;
}
