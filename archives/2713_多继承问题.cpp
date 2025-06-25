// INFO: 💩
//
// Description
// 现在有一个多继承问题，需要你用C++类的继承关系来实现出来。
// 现在有A、B、C、D、E、F六个类，每个类比自己的父类（如果有的话）多存储一个int类型的成员变量，
// 每个类都有一个函数用来返回这个成员变量的数据，这个函数名称是与自己类名相同的小写字母。
// 这六个类满足如下继承关系：A是B、C、D的父类，B和C是E的父类，C和D是F的父类。
// 在构造函数里添加适当的代码产生符合对象构造次序的输出。
// 程序代码见“Append Code”。
//
// Input
// 先输入一个n，表示后面有n行数据，每行首先输入一个字符表示类名，然后输入四个整数，用于创建该类的对象。
//
// Output
// 输出对象中存储的数据。

// Sample Input
// 2
// B 20 30 40 50 
// F 666 777 888 999

// Sample Output
// Create A : 20
// Create B : 20 30
// 20 30
// ----------
// Create A : 666
// Create C : 666 777
// Create D : 666 888
// Create F : 666 777 888 999
// 666 777 888 999
// ----------

#include <iostream>
using namespace std;
 
struct A {
  int _a;
  A(int a) : _a(a) {
    cout << "Create A : " << a << endl;
  }
  int a() {
    return _a;
  }
};
 
struct B : virtual A {
  int _b;
  B(int a, int b) : A(a), _b(b) {
    cout << "Create B : " << a << " " << b << endl;
  }
  int b() {
    return _b;
  }
};
 
struct C : virtual A {
  int _c;
  C(int a, int c) : A(a), _c(c) {
    cout << "Create C : " << a << " " << c << endl;
  }
  int c() {
    return _c;
  }
};
 
struct D : virtual A {
  int _d;
  D(int a, int d) : A(a), _d(d) {
    cout << "Create D : " << a << " " << d << endl;
  }
  int d() {
    return _d;
  }
};
 
struct E : B, C {
  int _e;
  E(int a, int b, int c, int e) : A(a), B(a, b), C(a, c), _e(e) {
    cout << "Create E : " << a << " " << b << " " << c << " " << e << endl;
  }
  int e() {
    return _e;
  }
};
 
struct F : C, D {
  int _f;
  F(int a, int c, int d, int f) : A(a), C(a, c), D(a, d), _f(f) {
    cout << "Create F : " << a << " " << c << " " << d << " " << f << endl;
  }
  int f() {
    return _f;
  }
};
 
// Append Code
int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        char ch;
        int x, y, z, w;
        cin >> ch;
        cin >> x >> y >> z >> w;
        if(ch == 'A')
        {
            A va(x);
            cout << va.a() << endl;
        }
        if(ch == 'B')
        {
            B vb(x, y);
            cout << vb.a() << " " << vb.b() << endl;
        }
        if(ch == 'C')
        {
            C vc(x, y);
            cout << vc.a() << " " << vc.c() << endl;
        }
        if(ch == 'D')
        {
            D vd(x, y);
            cout << vd.a() << " " << vd.d() << endl;
        }
        if(ch == 'E')
        {
            E ve(x, y, z, w);
            cout << ve.a() << " " << ve.b() << " " << ve.c() << " " << ve.e() << endl;
        }
        if(ch == 'F')
        {
            F vf(x, y, z, w);
            cout << vf.a() << " " << vf.c() << " " << vf.d() << " " << vf.f() << endl;
        }
        cout << "----------" << endl;
    }
}
