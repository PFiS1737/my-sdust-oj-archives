// INFO: 更安全和完整的做法，遵守 Rule of Three
//
// Description
// 定义类Point表示一个N维空间中的坐标，定义PointList为若干个Point对象组成的列表。定义：
// 1.Point::Point(n)方法：用于将坐标的维数设置为n。
// 2.重载Point的>>运算符，根据Input的格式进行输入一个坐标。
// 3.重载PointList的<<运算符，根据Output的格式输出PointList的所有坐标值。
// 4.PointList::Sort()：对PointList中的顶点按照到坐标原点的距离，从小到大排序。
// 5.重载PointList的+运算符，用于向列表中追加一个点的坐标。
// 其他所需要的数据成员、函数成员自行定义。
//
// Input
// 输入有多行。
// 第一行是两个正整数M和N，其中M表示之后有M个点的坐标，N表示每个点的维数。如M=3,N=2表示有3个二维空间中的点。
// 之后的M行，每行包含N个整数，表示一个点的坐标。
//
// Output
// 输出有M行，每行一个点的坐标。
// 输出时，按照到坐标原点，即[0,0,0,......]的距离从小到大输出。不存在距离相同的点。
// 每个点的坐标输出格式为：[d1,d2,...]，即：用[]包围一个点的坐标，输出的坐标值两两之间用逗号隔开。

// Sample Input
// 10 2
// 7 7
// 3 3
// 2 2
// 6 6
// 9 9
// 1 1
// 4 4
// 5 5
// 0 0
// 8 8

// Sample Output
// [0,0]
// [1,1]
// [2,2]
// [3,3]
// [4,4]
// [5,5]
// [6,6]
// [7,7]
// [8,8]
// [9,9]

#include <iostream>
using namespace std;

struct Point {
  int *data;
  int dim;
  int sqdmag; // Squared magnitude

  Point(int n = 0) : data(n ? new int[n] : NULL), dim(n), sqdmag(0) {
  }

  Point(const Point &p) : data(new int[p.dim]), dim(p.dim), sqdmag(p.sqdmag) {
    copy(p.data, p.data + p.dim, data);
  }

  Point &operator=(const Point &p) {
    if (this == &p)
      return *this;

    Point tmp(p);
    dim = tmp.dim;
    sqdmag = tmp.sqdmag;
    swap(data, tmp.data);

    return *this;
  }

  ~Point() {
    delete[] data;
  }

  friend istream &operator>>(istream &is, Point &p) {
    for (int i = 0; i < p.dim; i++) {
      is >> p.data[i];
      p.sqdmag += p.data[i] * p.data[i];
    }
    return is;
  }

  friend ostream &operator<<(ostream &os, const Point &p) {
    os << "[";
    for (int i = 0; i < p.dim; i++) {
      os << (i ? "," : "") << p.data[i];
    }
    os << "]";
    return os;
  }
};

struct PointList {
  Point *pos;
  int len;

  PointList() : pos(new Point[10000]), len(0) {
  }

  PointList(const PointList &pl) : pos(new Point[10000]), len(pl.len) {
    copy(pl.pos, pl.pos + pl.len, pos);
  }

  PointList &operator=(const PointList &pl) {
    if (this == &pl)
      return *this;

    PointList tmp(pl);
    len = tmp.len;
    swap(pos, tmp.pos);

    return *this;
  }

  ~PointList() {
    delete[] pos;
  }

  PointList operator+(const Point &p) {
    PointList ret(*this);
    ret.pos[ret.len++] = p;
    return ret;
  }

  void Sort() {
    for (int i = 0; i < len - 1; i++) {
      for (int j = 0; j < len - i - 1; j++) {
        if (pos[j].sqdmag > pos[j + 1].sqdmag) {
          swap(pos[j], pos[j + 1]);
        }
      }
    }
  }

  friend ostream &operator<<(ostream &os, const PointList &pl) {
    for (int i = 0; i < pl.len; i++) {
      os << pl.pos[i] << endl;
    }
    return os;
  }
};

// Append Code
int main() {
  PointList pl;
  int m, n, i;
  cin >> m >> n;
  for (i = 0; i < m; i++) {
    Point tmp(n);
    cin >> tmp;
    pl = pl + tmp;
  }
  pl.Sort();
  cout << pl;
  return 0;
}
