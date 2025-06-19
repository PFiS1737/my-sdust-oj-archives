// Description
// 封装一个时间类Time，在类上重载以下运算符，使得main()函数能够正确运行。
// 流插入操作符“>>”，按照输入格式从标准输入读取三个整数：hh,mm,ss，分别表示时、分、秒，其值在int范围内。
// 流提取操作符“<<”；按照“hh:mm:ss”输出Time类的对象，不合法的时间输出“error!!!”。
// 前置自增运算符“++”：把时间对象的秒数加1并返回。
// 前置自减运算符“--”：把时间对象的秒数减1并返回。
// 后置自增运算符“++”：把时间对象的秒数加1，返回原值。
// 后置自减运算符“--”：把时间对象的秒数减1，返回原值。
// 以上4个自增、自减仅对合法的时间操作，并且不会产生不合法的时间。比如：
// 若原时间对象为“00:00:00”，自减运算后的对象为“23:59:59”;
// 若原时间对象为“23:59:59”，自增运算后的对象为“00:00:00”;
// 若原时间对象为“24:60:60”，自增或自减运算后对象仍为“24:60:60”。
// 函数调用格式见append.cc。
// append.cc中已给出main()函数
//
// Input
// 输入的第一个整数n，表示有n组测试数据，每组3个整数：hh,mm,ss，分别表示时、分、秒，其值都在int范围内。
//
// Output
// 输出一张表：每列8个字符宽，两列之间有一个空格。
// 首先，输出一个表头：“++t      --t      t        t--      t++      t       ”，
// 其次，对应每组测试数据在一行内依次以下内容：
// 前置++、前置--、原值、后置--、后置++、原值。
// 若输入的日期合法，输出格式为“hh:mm:ss”，不足两位的输出需要前面补0。如果输入的时间不合法，则输出“error!!!”。格式见sample。

// Sample Input
// 6
// 0 0 1
// 0 59 59
// 1 1 60
// 23 0 0
// 23 59 59
// 24 1 0

// Sample Output
// ++t      --t      t        t--      t++      t       
// 00:00:02 00:00:01 00:00:01 00:00:01 00:00:00 00:00:01
// 01:00:00 00:59:59 00:59:59 00:59:59 00:59:58 00:59:59
// error!!! error!!! error!!! error!!! error!!! error!!!
// 23:00:01 23:00:00 23:00:00 23:00:00 22:59:59 23:00:00
// 00:00:00 23:59:59 23:59:59 23:59:59 23:59:58 23:59:59
// error!!! error!!! error!!! error!!! error!!! error!!!

#include <iomanip>
#include <iostream>
using namespace std;
 
struct Time {
  int hr, min, sec;
 
  Time() : hr(0), min(0), sec(0) {
  }
 
  bool valid() const {
    return (hr >= 0 && hr < 24) && (min >= 0 && min < 60) && (sec >= 0 && sec < 60);
  }
 
  friend istream &operator>>(istream &is, Time &t) {
    is >> t.hr >> t.min >> t.sec;
    return is;
  }
 
  friend ostream &operator<<(ostream &os, const Time &t) {
    if (!t.valid()) {
      cout << "error!!!";
      return os;
    }
    os << (t.hr < 10 ? "0" : "") << t.hr << ":" << (t.min < 10 ? "0" : "") << t.min << ":"
       << (t.sec < 10 ? "0" : "") << t.sec;
    return os;
  }
 
  Time &operator+=(int s) {
    if (!valid())
      return *this;
 
    sec += s;
    if (sec >= 60) {
      min += sec / 60;
      sec %= 60;
    }
    if (min >= 60) {
      hr += min / 60;
      min %= 60;
    }
    hr %= 24;
 
    return *this;
  }
 
  Time &operator-=(int s) {
    if (!valid())
      return *this;
 
    sec -= s;
    while (sec < 0) {
      sec += 60;
      min--;
    }
    while (min < 0) {
      min += 60;
      hr--;
    }
    hr = (hr + 24) % 24;
 
    return *this;
  }
 
  Time &operator++() {
    return *this += 1;
  }
 
  Time operator++(int) {
    Time ret = *this;
    ++(*this);
    return ret;
  }
 
  Time &operator--() {
    return *this -= 1;
  }
 
  Time operator--(int) {
    Time ret = *this;
    --(*this);
    return ret;
  }
};
 
// Append Code
int main()
{
    Time t;
    int cases;
    cin>>cases;
    cout<<setw(8)<<left<<"++t"<<" ";
    cout<<setw(8)<<left<<"--t"<<" ";
    cout<<setw(8)<<left<<"t"<<" ";
    cout<<setw(8)<<left<<"t--"<<" ";
    cout<<setw(8)<<left<<"t++"<<" ";
    cout<<setw(8)<<left<<"t"<<right<<endl;
    for(int i = 1; i <= cases; ++i)
    {
        cin>>t;
        cout<<(++t)<<" ";
        cout<<(--t)<<" ";
        cout<<t<<" ";
        cout<<t--<<" ";
        cout<<t++<<" ";
        cout<<t<<endl;
    }
}
