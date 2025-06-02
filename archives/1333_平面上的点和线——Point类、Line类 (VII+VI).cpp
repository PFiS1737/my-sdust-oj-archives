// Description
// 在数学上，平面直角坐标系上的点用X轴和Y轴上的两个坐标值唯一确定，两点确定一条线段。现在我们封装一个“Point类”和“Line类”来实现平面上的点的操作。
// 根据“append.cc”，完成Point类和Line类的构造方法和show()方法，输出各Line对象和Point对象的构造和析构次序。
// 接口描述：
// Point::show()方法：按格式输出Point对象。
// Point::x()方法：取x坐标。
// Point::y()方法：取y坐标。
// Line::show()方法：按格式输出Line对象。
// Line::SetLine(double, double, double, double)方法：设置Line对象起点的x,y坐标（第一个和第二参数）和终点的x,y坐标（第三个和第四个坐标），并返回本对象
// Line::SetLine(const Point &, const Point &)方法：设置Line对象的起点（第一个参数）和终点（第二个坐标），并返回本对象
// Line::SetLine(const Line&)方法：设置Line对象，复制参数的坐标，并返回本对象
// Line::readLine()方法：从标准输入上读入坐标，格式见Sample
// Line::start()方法：取Line的起点
// Line::end()方法：取Line的终点
// Line::setStart()方法：设置Line的起点
// Line::setEnd()方法：设置Line的终点
// Point::showCounter()方法：按格式输出当前程序中Point对象的计数。
// Point::showSum()方法：按格式输出程序运行至当前存在过的Point对象总数。
// Line::showCounter()方法：按格式输出当前程序中Line对象的计数。
// Line::showSum()方法：按格式输出程序运行至当前存在过的Line对象总数。
//
// Input
// 输入的第一行为N，表示后面有N行测试样例。
// 每行为两组坐标“x,y”，分别表示线段起点和终点的x坐标和y坐标，两组坐标间用一个空格分开，x和y的值都在double数据范围内。
//
// Output
// 输出为多行，每行为一条线段，起点坐标在前终点坐标在后，每个点的X坐标在前，Y坐标在后，Y坐标前面多输出一个空格，用括号包裹起来。输出格式见sample。
// C语言的输入输出被禁用。

// Sample Input
// 4
// 0,0 1,1
// 1,1 2,3
// 2,3 4,5
// 0,1 1,0

// Sample Output
// Point : (1, -2) is created.
// Point : (2, -1) is created.
// Point : (0, 0) is created.
// Current : 3 points.
// In total : 3 points.
// Point : (0, 0) is created.
// Point : (0, 0) is created.
// Line : (0, 0) to (0, 0) is created.
// Point : (0, 0) is created.
// Point : (0, 0) is created.
// Line : (0, 0) to (0, 0) is created.
// Point : (0, 0) is created.
// Point : (0, 0) is created.
// Line : (0, 0) to (0, 0) is created.
// Point : (0, 0) is created.
// Point : (0, 0) is created.
// Line : (0, 0) to (0, 0) is created.
// Point : (0, 0) is created.
// Point : (0, 0) is created.
// Line : (0, 0) to (0, 0) is created.
// Point : (0, 0) is created.
// Point : (0, 0) is created.
// Line : (0, 0) to (0, 0) is created.
// Current : 6 lines.
// In total : 6 lines.
// Point : (1, -2) is copied.
// Point : (2, -1) is copied.
// Line : (1, -2) to (2, -1) is created.
// Line : (0, 0) to (1, 1)
// Current : 17 points.
// In total : 17 points.
// Line : (1, -2) to (2, -1) is erased.
// Point : (2, -1) is erased.
// Point : (1, -2) is erased.
// Current : 6 lines.
// In total : 7 lines.
// Current : 15 points.
// In total : 17 points.
// Line : (0, 0) to (0, 0) is erased.
// Point : (0, 0) is erased.
// Point : (0, 0) is erased.
// Point : (0, 0) is created.
// Point : (0, 0) is created.
// Line : (0, 0) to (0, 0) is created.
// Current : 6 lines.
// In total : 8 lines.
// Point : (1, -2) is copied.
// Point : (2, -1) is copied.
// Line : (1, -2) to (2, -1) is created.
// Line : (1, 1) to (2, 3)
// Current : 17 points.
// In total : 21 points.
// Line : (1, -2) to (2, -1) is erased.
// Point : (2, -1) is erased.
// Point : (1, -2) is erased.
// Current : 6 lines.
// In total : 9 lines.
// Current : 15 points.
// In total : 21 points.
// Line : (0, 0) to (0, 0) is erased.
// Point : (0, 0) is erased.
// Point : (0, 0) is erased.
// Point : (0, 0) is created.
// Point : (0, 0) is created.
// Line : (0, 0) to (0, 0) is created.
// Current : 6 lines.
// In total : 10 lines.
// Point : (1, -2) is copied.
// Point : (2, -1) is copied.
// Line : (1, -2) to (2, -1) is created.
// Line : (2, 3) to (4, 5)
// Current : 17 points.
// In total : 25 points.
// Line : (1, -2) to (2, -1) is erased.
// Point : (2, -1) is erased.
// Point : (1, -2) is erased.
// Current : 6 lines.
// In total : 11 lines.
// Current : 15 points.
// In total : 25 points.
// Line : (0, 0) to (0, 0) is erased.
// Point : (0, 0) is erased.
// Point : (0, 0) is erased.
// Point : (0, 0) is created.
// Point : (0, 0) is created.
// Line : (0, 0) to (0, 0) is created.
// Current : 6 lines.
// In total : 12 lines.
// Point : (1, -2) is copied.
// Point : (2, -1) is copied.
// Line : (1, -2) to (2, -1) is created.
// Line : (0, 1) to (1, 0)
// Current : 17 points.
// In total : 29 points.
// Line : (1, -2) to (2, -1) is erased.
// Point : (2, -1) is erased.
// Point : (1, -2) is erased.
// Current : 6 lines.
// In total : 13 lines.
// Current : 15 points.
// In total : 29 points.
// Line : (0, 0) to (0, 0) is erased.
// Point : (0, 0) is erased.
// Point : (0, 0) is erased.
// Point : (1, -2) is copied.
// Point : (2, -1) is copied.
// Line : (1, -2) to (2, -1) is created.
// Point : (1, -2) is copied.
// Point : (0, 0) is copied.
// Line : (1, -2) to (0, 0) is created.
// Point : (2, -1) is copied.
// Point : (0, 0) is copied.
// Line : (2, -1) to (0, 0) is created.
// Point : (1, -2) is copied.
// Point : (2, -1) is copied.
// Line : (1, -2) to (2, -1) is copied.
// Line : (1, -2) to (2, -1)
// Line : Point : (1, -2) to Point : (0, 0)
// Line : Point : (1, -2) to Point : (2, -1)
// Line : (0, 0) to (2, -1)
// Current : 9 lines.
// In total : 17 lines.
// Current : 21 points.
// In total : 37 points.
// Point : (0, 0) is created.
// Point : (0, 0) is created.
// Line : (0, 0) to (0, 0) is created.
// Point : (0, 0) is created.
// Point : (0, 0) is created.
// Line : (0, 0) to (0, 0) is created.
// Point : (0, 0) is created.
// Point : (0, 0) is created.
// Line : (0, 0) to (0, 0) is created.
// Point : (0, 0) is created.
// Point : (0, 0) is created.
// Line : (0, 0) to (0, 0) is created.
// Current : 13 lines.
// In total : 21 lines.
// Line : (0, 0) to (0, 0) is erased.
// Point : (0, 0) is erased.
// Point : (0, 0) is erased.
// Line : (0, 0) to (0, 0) is erased.
// Point : (0, 0) is erased.
// Point : (0, 0) is erased.
// Line : (0, 0) to (0, 0) is erased.
// Point : (0, 0) is erased.
// Point : (0, 0) is erased.
// Line : (0, 0) to (0, 0) is erased.
// Point : (0, 0) is erased.
// Point : (0, 0) is erased.
// Current : 21 points.
// In total : 45 points.
// Line : (0, 0) to (2, -1) is erased.
// Point : (2, -1) is erased.
// Point : (0, 0) is erased.
// Line : (1, -2) to (2, -1) is erased.
// Point : (2, -1) is erased.
// Point : (1, -2) is erased.
// Line : (1, -2) to (0, 0) is erased.
// Point : (0, 0) is erased.
// Point : (1, -2) is erased.
// Line : (1, -2) to (2, -1) is erased.
// Point : (2, -1) is erased.
// Point : (1, -2) is erased.
// Line : (0, 1) to (1, 0) is erased.
// Point : (1, 0) is erased.
// Point : (0, 1) is erased.
// Line : (2, 3) to (4, 5) is erased.
// Point : (4, 5) is erased.
// Point : (2, 3) is erased.
// Line : (1, 1) to (2, 3) is erased.
// Point : (2, 3) is erased.
// Point : (1, 1) is erased.
// Line : (0, 0) to (1, 1) is erased.
// Point : (1, 1) is erased.
// Point : (0, 0) is erased.
// Line : (0, 0) to (2, -1) is erased.
// Point : (2, -1) is erased.
// Point : (0, 0) is erased.
// Point : (0, 0) is erased.
// Point : (2, -1) is erased.
// Point : (1, -2) is erased.

#include <iostream>
using namespace std;

struct Point {
  double _x, _y;

  static int counter;
  static int total;

  static void showCounter() {
    cout << "Current : " << counter << " points." << endl;
  }
  static void showSum() {
    cout << "In total : " << total << " points." << endl;
  }

  basic_ostream<char> &print() const {
    return cout << "Point : (" << _x << ", " << _y << ")";
  }

  void log(string s) {
    print() << " is " << s << "." << endl;
  }

  Point() : _x(0), _y(0) {
    log("created");
    counter++;
    total++;
  }
  Point(double x, double y) : _x(x), _y(y) {
    log("created");
    counter++;
    total++;
  }
  Point(double n) : _x(n), _y(n) {
    log("created");
    counter++;
    total++;
  }
  Point(const Point &p) : _x(p._x), _y(p._y) {
    log("copied");
    counter++;
    total++;
  }

  void show() const {
    print() << endl;
  }
  void showNoEndOfLine() const {
    print();
  }

  double x() const {
    return _x;
  }
  double y() const {
    return _y;
  }

  ~Point() {
    log("erased");
    counter--;
  }
};

struct Line {
  Point p1, p2;

  static int counter;
  static int total;

  static void showCounter() {
    cout << "Current : " << counter << " lines." << endl;
  }
  static void showSum() {
    cout << "In total : " << total << " lines." << endl;
  }

  basic_ostream<char> &print() const {
    return cout << "Line : (" << p1._x << ", " << p1._y << ") to (" << p2._x << ", "
                << p2._y << ")";
  }

  void log(string s) {
    print() << " is " << s << "." << endl;
  }

  Line(double x1, double y1, double x2, double y2) : p1(x1, y1), p2(x2, y2) {
    log("created");
    counter++;
    total++;
  }

  Line() : p1(), p2() {
    log("created");
    counter++;
    total++;
  }

  Line(const Point &p1, const Point &p2) : p1(p1), p2(p2) {
    log("created");
    counter++;
    total++;
  }

  Line(const Line &l) : p1(l.p1), p2(l.p2) {
    log("copied");
    counter++;
    total++;
  }

  void show() const {
    print() << endl;
  }

  void readLine() {
    char _;
    cin >> p1._x >> _ >> p1._y >> p2._x >> _ >> p2._y;
  }

  Line setLine(double x1, double y1, double x2, double y2) {
    p1._x = x1;
    p1._y = y1;
    p2._x = x2;
    p2._y = y2;

    return *this;
  }
  Line &setLine(Line &l) {
    setStart(l.p1);
    setEnd(l.p2);

    return *this;
  }
  Line &setLine(const Point &p1, const Point &p2) {
    setStart(p1);
    setEnd(p2);

    return *this;
  }

  const Point &start() const {
    return p1;
  }
  void setStart(const Point &p) {
    p1 = p;
  }
  const Point &end() const {
    return p2;
  }
  void setEnd(const Point &p) {
    p2 = p;
  }

  ~Line() {
    log("erased");
    counter--;
  }
};

int Point::counter = 0;
int Point::total = 0;
int Line::counter = 0;
int Line::total = 0;

// Append Code
void showLineCoordinate(const Line &line) {
  std::cout << "Line : ";
  std::cout << "(" << line.start().x() << ", " << line.start().y() << ")";
  std::cout << " to ";
  std::cout << "(" << line.end().x() << ", " << line.end().y() << ")";
  std::cout << std::endl;
}

void showLinePoint(const Line &line) {
  std::cout << "Line : ";
  line.start().showNoEndOfLine();
  std::cout << " to ";
  line.end().showNoEndOfLine();
  std::cout << std::endl;
}

int main() {
  int num, i;
  Point p(1, -2), q(2, -1), t;
  t.showCounter();
  t.showSum();
  std::cin >> num;
  Line line[num + 1];
  for (i = 1; i <= num; i++) {
    Line *l1, l2;
    l1->showCounter();
    l1->showSum();
    l1 = new Line(p, q);
    line[i].readLine();
    line[i].show();
    p.showCounter();
    p.showSum();
    delete l1;
    l2.showCounter();
    l2.showSum();
    q.showCounter();
    q.showSum();
  }
  Line l1(p, q), l2(p, t), l3(q, t), l4(l1);
  showLineCoordinate(l1);
  showLinePoint(l2);
  showLinePoint(l3.setLine(l1));
  showLineCoordinate(l4.setLine(t, q));
  line[0].setStart(t);
  line[0].setEnd(q);
  Line::showCounter();
  Line::showSum();
  Point::showCounter();
  Point::showSum();
  Line *l = new Line[num];
  l4.showCounter();
  l4.showSum();
  delete[] l;
  t.showCounter();
  t.showSum();
}
