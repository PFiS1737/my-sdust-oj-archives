// INFO: 💩
//
// Description
// 现在要开发一个儿童绘画游戏。多名儿童可以在同一个软件中，绘制长方形和圆形。请至少定义如下类及其成员：
// 1.Shape类：图形类，包括一个静态成员函数getCntOfShapes()用于获得总共绘制了多少个图形。
// 2.Rectangle类：矩形类，是Shape类的子类，包括：
// （1）两个double类型的属性，表示矩形的长、宽。
// （2）静态成员函数getCntOfRects()用于获取绘制的矩形的个数。
// 3.Circle类：圆形类，是Shape类的子类，包括：
// （1）一个double类型的属性，是圆形的半径。
// （2）静态成员函数getCntOfCircles()用于获得圆形的个数。
// 4.User类：用户类，包括：
// （1）一个string类型属性，是用户的名字。
// （2）一个Shape的列表，表示该用户绘制的图形的列表。
// （3）构造函数User(string s)，参数s是用户名。
// （4）静态成员函数getCntOfUsers()用于获取用户个数。
// （5）addAShape(int t,double a,double b)：如果t=1，则表示绘制了一个矩形，其长、宽即a和b；如果t=2，则表示绘制了一个圆形，半径为a。
// （6）double getArea()方法：返回该用户绘制的所有图形的面积。
// 5.UserList类：用户列表类，包括：
// （1）一个User的列表。
// （2）showTotalArea(string s)方法：如果s指定的用户名存在，则输出相应用户的绘制的图形的面积之和；如果s指定的用户不存在，则输出：
// The user $ doesn't exist.
// 其中$为s的值。
// （3）重载的输入运算符，用于输入所有的用户及他们绘制的图形。输入格式为：
// 第1行整数N>0，表示有N个用户，后面的N行，每行对应一个用户。
// 每个用户的第1个字符串是该用户的名字。之后是一个正整数M，表示该用户绘制了M个图形。之后有M组输入，每组输入第1个整数t表示图形的类型，1和2分别表示矩形和圆形；如果t为1，则之后的2个实数是矩形的长、宽；如果t为2，则之后的1个实数为圆形的半径。
// （4）重载的输出运算符，按照如下格式输出所有用户及其绘制的图形：
// 每个用户占一行，格式为：
// $ : rect(a,b),circle(r),…
// 其中，$为用户名。冒号之后是该用户绘制的图形的列表，输出顺序与输入顺序相同。如果该图形是矩形，则输出”rect(a,b)”，其中a和b是矩形的长、宽；如果该图形是圆形，则输出”circle(r)”，其中r是半径。输出的图形信息两两之间用一个逗号隔开。
//
// Input
// 输入分为2部分。
// 第1部分是按照UserList类的要求输入的用户及图形信息。
// 第2部分有多行，每行包括1个字符串，是一个用户名。
// 假定所有的用户名均不相同。
//
// Output
// 见样例。

// Sample Input
// 3
// Tom 3 1 1.1 2.2 2 3.3 1 2.1 3.2
// Jerry 2 2 3.1 2 4.4
// Mary 4 1 1.3 1.4 1 2.5 3.1 2 3.5 2 5.6
// CUI
// Tom
// Jerry
// mary
// Mary

// Sample Output
// In beginning, 0 users,0 shapes.
// 30.26
// Now, 4 users,11 shapes, including 6 circles, and 5 rectangles.
// Tom : rect(1.1,2.2),circle(3.3),rect(2.1,3.2)
// Jerry : circle(3.1),circle(4.4)
// Mary : rect(1.3,1.4),rect(2.5,3.1),circle(3.5),circle(5.6)
// The user CUI doesn't exist.
// 43.3346
// 90.9658
// The user mary doesn't exist.
// 146.505

#include <iostream>
#include <vector>
using namespace std;
 
struct Shape {
  static int cnt;
  Shape() {
    cnt++;
  }
  static int getCntOfShapes() {
    return cnt;
  }
  virtual double getArea() = 0;
  virtual void print(ostream &os) = 0;
};
int Shape::cnt = 0;
 
struct Circle : Shape {
  double radius;
  static int cnt;
  Circle(double r) : radius(r) {
    cnt++;
  }
  static int getCntOfCircles() {
    return cnt;
  }
  double getArea() {
    return 3.14 * radius * radius;
  }
  void print(ostream &os) {
    os << "circle(" << radius << ")";
  }
};
int Circle::cnt = 0;
 
struct Rectangle : Shape {
  double width, height;
  static int cnt;
  Rectangle(double h, double w) : width(w), height(h) {
    cnt++;
  }
  static int getCntOfRects() {
    return cnt;
  }
  double getArea() {
    return width * height;
  }
  void print(ostream &os) {
    os << "rect(" << height << "," << width << ")";
  }
};
int Rectangle::cnt = 0;
 
struct User {
  static int cnt;
  string name;
  vector<Shape *> shapes;
  User(string n) : name(n) {
    cnt++;
  }
  static int getCntOfUsers() {
    return cnt;
  }
  void addAShape(int type, double a, double b = 0) {
    if (type == 1) {
      shapes.push_back(new Rectangle(a, b));
    } else if (type == 2) {
      shapes.push_back(new Circle(a));
    }
  }
  double getArea() const {
    double sum = 0;
    for (size_t i = 0; i < shapes.size(); i++) {
      sum += shapes[i]->getArea();
    }
    return sum;
  }
};
int User::cnt = 0;
 
struct UserList {
  vector<User *> users;
  friend istream &operator>>(istream &is, UserList &l) {
    int n;
    cin >> n;
    while (n--) {
      string name;
      cin >> name;
      User *user = new User(name);
      int m;
      is >> m;
      while (m--) {
        int type;
        double a, b = 0;
        is >> type >> a;
        if (type == 1) {
          is >> b;
        }
        user->addAShape(type, a, b);
      }
      l.users.push_back(user);
    }
    return is;
  }
  friend ostream &operator<<(ostream &os, const UserList &lst) {
    for (size_t i = 0; i < lst.users.size(); i++) {
      os << lst.users[i]->name << " : ";
      for (size_t j = 0; j < lst.users[i]->shapes.size(); j++) {
        if (j) {
          os << ",";
        }
        lst.users[i]->shapes[j]->print(os);
      }
      os << endl;
    }
    return os;
  }
  void showTotalArea(const string &name) const {
    for (size_t i = 0; i < users.size(); i++) {
      if (users[i]->name == name) {
        cout << users[i]->getArea() << endl;
        return;
      }
    }
    cout << "The user " << name << " doesn't exist." << endl;
  }
};
 
// Append Code
int main()
{
    cout<<"In beginning, "<<User::getCntOfUsers()<<" users,";
    cout<<Shape::getCntOfShapes()<<" shapes."<<endl;
    User tmp("C++");
    tmp.addAShape(1, 1, 2);
    tmp.addAShape(2, 3);
    cout<<tmp.getArea()<<endl;
 
    UserList lst;
    string s1;
    cin>>lst;
    cout<<"Now, "<<User::getCntOfUsers()<<" users,";
    cout<<Shape::getCntOfShapes()<<" shapes, including ";
    cout<<Circle::getCntOfCircles()<<" circles, and ";
    cout<<Rectangle::getCntOfRects()<<" rectangles."<<endl;
    cout<<lst;
    while(cin>>s1)
    {
        lst.showTotalArea(s1);
    }
    return 0;
}
