// Description
// 封装一个时间类Time，用于时间处理的相关功能，支持以下操作：
// 1. Time::Time()无参构造方法。
// 2. 成员读函数：
//    Time::hour()  ：返回Time的小时数；
//    Time::minute()：返回Time的分钟数；
//    Time::second()：返回Time的秒数。
// 3. 成员写函数：
//    Time::hour(int)  ：传参修改Time的小时数；
//    Time::minute(int)：传参修改Time的分钟数；
//    Time::second(int)：传参修改Time的秒数。
// 你设计一个时间类Time，使得main()函数能够正确运行。
// 函数调用格式见append.cc。
// append.cc中已给出main()函数。
//
// Input
// 输入的第一个整数n，表示有n组测试数据，每组3个整数：hh,mm,ss，分别表示时、分、秒，其值都在合法的时间范围内。
//
// Output
// 每组测试数据对应一组输出“hh:mm:ss”，不足两位的输出需要前面补0，格式见sample。

// Sample Input
// 5
// 0 0 1
// 0 59 59
// 1 1 1
// 23 0 0
// 23 59 59

// Sample Output
// 00:00:01
// 00:59:59
// 01:01:01
// 23:00:00
// 23:59:59

#include <iostream>
#include <iomanip>
using namespace std;

class Time {
  int h,m,s;

public:
  Time() : h(0), m(0), s(0) {}

  void hour(int h) {
    this->h = h % 24;
  }

  void minute(int m) {
    this->m = m % 60;
  }

  void second(int s) {
    this->s = s % 60;
  }

  int hour() {
    return h;
  }

  int minute(){
    return m;
  }

  int second() {
    return s;
  }
};

// Append Code Start
int main()
{
    Time t;
    int cases;
    cin>>cases;
    for(int i = 1; i <= cases; ++i)
    {
        int hour, minute, second;
        cin>>hour>>minute>>second;
        t.hour(hour);
        t.minute(minute);
        t.second(second);
        cout<<setw(2)<<setfill('0')<<t.hour()<<":";
        cout<<setw(2)<<setfill('0')<<t.minute()<<":";
        cout<<setw(2)<<setfill('0')<<t.second()<<endl;
    }
}
// Append Code End
