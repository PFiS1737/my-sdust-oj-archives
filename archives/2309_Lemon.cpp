// INFO: 💩
//
// Description
// Jackie开了一家水果店，店里柑橘类（Citrus）水果销售情况特别好，刚刚进货了一些砂糖柑（Tangerine）、葡萄柚（Grapefruit）和柠檬（Lemon）。
// 他有兴趣研究了柑橘类水果的杂交过程（如下图所示）：
// 首先，橘子（Mandarin）、柚子（Pomelo）和香橼（Cirton）都是柑橘类（Citrus）的水果，这是第一层；
// 其次，第二层的水果是橙子（Orange）和青柠（Lime），橙子是橘子和柚子杂交出来的，柚子和香橼杂交出了青柠；
// 最后是第三层，橘柑（砂糖柑）是橘子和橙子杂交的产物，葡萄柚是橙子和柚子杂交的结果，橙子和青柠杂交产生了柠檬。
// 请你编写程序用派生树来描述柑橘类水果的杂交关系，用继承关系来表示柑橘类水果的杂交过程。
// 用C++编写Citrus类及其派生树上的各个类来来完成代码，调用格式见“Append Code”。
// Citrus类及其派生树上的这些类的属性是名称（name）和重量（weight）、有show()函数用来显示一些信息。各类的构造根据给出的调用代码完成。
//
// Input
// 输入为多行，每行是一种水果的名称和重量。
//
// Output
// 按格式输出水果的信息，详细见输出样例。

// Sample Input
// Tangerine 150
// Grapefruit 200
// Lemon 1000

// Sample Output
// Tangerine 150kg, is citrus fruit.
// Tangerine 150kg, is mandarin.
// Tangerine 150kg, is orange.
// Tangerine 150kg, is tangerine.
// Grapefruit 200kg, is citrus fruit.
// Grapefruit 200kg, is pomelo.
// Grapefruit 200kg, is grapefruit.
// Lemon 1000kg, is mandarin.
// Lemon 1000kg, is pomelo.
// Lemon 1000kg, is citron.
// Lemon 1000kg, is orange.
// Lemon 1000kg, is lime.
// Lemon 1000kg, is lemon.

#include <iostream>
#include <string>
using namespace std;

struct Citrus {
  string name;
  double weight;
  Citrus(string &n, double w) : name(n), weight(w) {
  }
  void show() {
    cout << name << " " << weight << "kg, is citrus fruit." << endl;
  }
};

struct Mandarin : virtual Citrus {
  Mandarin(string &n, double w) : Citrus(n, w) {
  }
  void show() {
    cout << name << " " << weight << "kg, is mandarin." << endl;
  }
};

struct Pomelo : virtual Citrus {
  Pomelo(string &n, double w) : Citrus(n, w) {
  }
  void show() {
    cout << name << " " << weight << "kg, is pomelo." << endl;
  }
};

struct Citron : virtual Citrus {
  Citron(string &n, double w) : Citrus(n, w) {
  }
  void show() {
    cout << name << " " << weight << "kg, is citron." << endl;
  }
};

struct Orange : Mandarin, virtual Pomelo {
  Orange(string &n, double w) : Citrus(n, w), Pomelo(n, w), Mandarin(n, w) {
  }
  void show() {
    cout << name << " " << weight << "kg, is orange." << endl;
  }
};

struct Lime : virtual Pomelo, Citron {
  Lime(string &n, double w) : Citrus(n, w), Pomelo(n, w), Citron(n, w) {
  }
  void show() {
    cout << name << " " << weight << "kg, is lime." << endl;
  }
};

struct Tangerine : Orange {
  Tangerine(string &n, double w) : Citrus(n, w), Pomelo(n, w), Orange(n, w) {
  }
  void show() {
    cout << name << " " << weight << "kg, is tangerine." << endl;
  }
};

struct Grapefruit : Orange {
  Grapefruit(string &n, double w) : Citrus(n, w), Pomelo(n, w), Orange(n, w) {
  }
  void show() {
    cout << name << " " << weight << "kg, is grapefruit." << endl;
  }
};

struct Lemon : Orange, Lime {
  Lemon(string &n, double w) : Citrus(n, w), Pomelo(n, w), Orange(n, w), Lime(n, w) {
  }
  void show() {
    cout << name << " " << weight << "kg, is lemon." << endl;
  }
};

// Append Code
// clang-format off
int main()
{
    Citrus     *c;
    Mandarin   *ma;
    Pomelo     *po;
    Citron     *ci;
    Orange     *og;
    Lime       *li;
    Tangerine  *ta;
    Grapefruit *gr;
    Lemon      *le;
 
    string name;
    double weight;
    while(cin >> name >> weight)
    {
        if(name == "Tangerine")
        {
            Tangerine tangerine(name, weight);
            c = ma = og = ta = &tangerine;
            c->show();
            ma->show();
            og->show();
            ta->show();
        }
        if(name == "Grapefruit")
        {
            Grapefruit grapefruit(name, weight);
            c = po = gr = &grapefruit;
            c->show();
            po->show();
            gr->show();
        }
        if(name == "Lemon")
        {
            Lemon lemon(name, weight);
            ma = og = &lemon;
            ci = li = &lemon;
            po = le = &lemon;
            ma->show();
            po->show();
            ci->show();
            og->show();
            li->show();
            le->show();
        }
    }
}
