// Description
// 日期类（Date）由年月日组成，在日常使用中英国、美国、德国、西班牙的日期输出格式均不相同。
// 英国（BritishStyle类）的日期格式是“日/月/年”、
// 美国（AmericanStyle类）的日期格式是“月-日-年”、
// 德国（GermanStyle类）的日期格式是“年-月-日”、
// 西班牙（SpanishStyle类）的日期格式是“日-月-年”。
// 这里设计Date类用来存储年、月、日数据，BritishStyle类、AmericanStyle类、GermanStyle类、SpanishStyle类派生自Date类，用来改变输出格式。
//
// Input
// 输入为多组。每组包括年、月、日三个整数。
//
// Output
// 按格式输出日期。

// Sample Input
// 2021 7 17

// Sample Output
// construct Date 2021 7 17
// construct BritishStyle 2021 7 17
// construct Date 2021 7 17
// construct AmericanStyle 2021 7 17
// construct Date 2021 7 17
// construct GermanStyle 2021 7 17
// construct Date 2021 7 17
// construct SpanishStyle 2021 7 17
// 17/7/2021
// 7-17-2021
// 2021-7-17
// 17-7-2021
// destruct BritishStyle 2021 7 17
// destruct Date 2021 7 17
// destruct AmericanStyle 2021 7 17
// destruct Date 2021 7 17
// destruct GermanStyle 2021 7 17
// destruct Date 2021 7 17
// destruct SpanishStyle 2021 7 17
// destruct Date 2021 7 17

#include <iostream>
using namespace std;

struct Date {
  int _year;
  int _month;
  int _day;

  Date() : _year(1000), _month(1), _day(1) {
    cout << "construct Date " << _year << " " << _month << " " << _day << endl;
  }
  Date(int y, int m, int d) : _year(y), _month(m), _day(d) {
    cout << "construct Date " << _year << " " << _month << " " << _day << endl;
  }

  int year() const {
    return _year;
  }
  void year(int y) {
    _year = y;
  }
  int month() const {
    return _month;
  }
  void month(int m) {
    _month = m;
  }
  int day() const {
    return _day;
  }
  void day(int d) {
    _day = d;
  }

  virtual void print() const {
    cout << _year << "-" << _month << "-" << _day << endl;
  }

  virtual ~Date() {
    cout << "destruct Date " << _year << " " << _month << " " << _day << endl;
  }
};

struct BritishStyle : Date {
  BritishStyle() : Date() {
    cout << "construct BritishStyle " << _year << " " << _month << " " << _day << endl;
  }
  BritishStyle(int y, int m, int d) : Date(y, m, d) {
    cout << "construct BritishStyle " << _year << " " << _month << " " << _day << endl;
  }

  void print() const {
    cout << _day << "/" << _month << "/" << _year << endl;
  }

  ~BritishStyle() {
    cout << "destruct BritishStyle " << _year << " " << _month << " " << _day << endl;
  }
};

struct AmericanStyle : Date {
  AmericanStyle() : Date() {
    cout << "construct AmericanStyle " << _year << " " << _month << " " << _day << endl;
  }
  AmericanStyle(int y, int m, int d) : Date(y, m, d) {
    cout << "construct AmericanStyle " << _year << " " << _month << " " << _day << endl;
  }

  void print() const {
    cout << _month << "-" << _day << "-" << _year << endl;
  }

  ~AmericanStyle() {
    cout << "destruct AmericanStyle " << _year << " " << _month << " " << _day << endl;
  }
};

struct GermanStyle : Date {
  GermanStyle() : Date() {
    cout << "construct GermanStyle " << _year << " " << _month << " " << _day << endl;
  }
  GermanStyle(int y, int m, int d) : Date(y, m, d) {
    cout << "construct GermanStyle " << _year << " " << _month << " " << _day << endl;
  }
  ~GermanStyle() {
    cout << "destruct GermanStyle " << _year << " " << _month << " " << _day << endl;
  }
};

struct SpanishStyle : Date {
  SpanishStyle() : Date() {
    cout << "construct SpanishStyle " << _year << " " << _month << " " << _day << endl;
  }
  SpanishStyle(int y, int m, int d) : Date(y, m, d) {
    cout << "construct SpanishStyle " << _year << " " << _month << " " << _day << endl;
  }

  void print() const {
    cout << _day << "-" << _month << "-" << _year << endl;
  }

  ~SpanishStyle() {
    cout << "destruct SpanishStyle " << _year << " " << _month << " " << _day << endl;
  }
};

// Append Code
// clang-format off
int main()
{
    Date *date[100];
    int year, month, day, cases = 0;
    while(cin >> year >> month >> day)
    {
        date[cases++] = new BritishStyle(year, month, day);
        date[cases++] = new AmericanStyle(year, month, day);
        date[cases++] = new GermanStyle(year, month, day);
        date[cases++] = new SpanishStyle(year, month, day);
    }
    for(int i = 0; i < cases; i++)
        date[i]->print();
    for(int i = 0; i < cases; i++)
        delete date[i];
 
}
