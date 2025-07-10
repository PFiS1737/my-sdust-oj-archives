// INFO: 💩
//
// Description
// Yang要下海创业，开一家量贩式KTV。现在需要你来帮他编写一个C++程序来实现点歌的功能。至少需要定义如下类及其成员：
// 1. Song类：歌曲类，具有：
// （1）歌曲名属性：一个不含空白符的字符串。
// （2）static int getCntOfSongs()：获得创建的歌曲的总数。
// 2. Pop类：是Song类的子类，具有static int getCntOfPops()方法，返回该类型的歌曲的总数。
// 3. Folk类：是Song类的子类，具有static int getCntOfFolks()方法，返回该类型的歌曲的总数。
// 4. Bel类：是Song类的子类，具有static int getCntOfBels()方法，返回该类型的歌曲的总数。
// 5. Singer类：歌手类，具有：
// （1）歌手名属性：一个不含空白符的字符串。
// （2）所演唱的歌曲列表。
// （3）void addASong(string s, int t)：添加一首该歌手演唱的歌曲，其中s为歌曲名，t为歌曲类型（1、2、3分别表示Pop、Folk和Bel类的歌曲）。
// （4）void singASong(string)：根据指定的歌曲名，演唱这首歌。分为两种情况：如果歌手所演唱的歌曲列表中有参数指定的歌曲名，则输出：
// $ sings % in # style.
// 其中：$是歌手名字，%是歌曲名字，#是歌曲类型（为：popular、folk或Bel Canto之一）。
// 如果指定歌曲名不存在，则输出：
// $ doesn’t sing %.
// $、%含义同前。
// （5）static int getCntOfSingers()：获得创建的歌手的人数。
// 6.SingerList类：点歌单类，具有：
// （1）歌手列表。
// （2）重载的输入输出运算符。其中重载的输入运算符按照如下格式输入数据：
// 第1行N>0，表示有N名歌手。之后有N行。
// 之后的N行，每行是一个歌手及其演唱的歌曲，是一系列用空格分开的数据。每行的第一个字符串（不含空白符）是歌手的名字。第2个是整数M>0，表示该歌手演唱了M首歌曲。M后面有M组输入，每组输入包括1个整数K和1个不含空白符的字符串S，其中K=1、2或者3，分别对应于pop、folk和Bel Canto三种歌曲类型，S是歌曲名。
// 重载的输出运算符按照如下格式输出歌手及歌曲列表：
// 每个歌手及其演唱的歌曲占一行，每行的格式为：
// $ : %1 %2 …
// 其中$为歌手名，%1、%2等为该歌手演唱的歌曲名列表，两两之间用1个空格隔开。
// （3）void Choose(string s1, string s2)方法：根据参数指定的歌手名s1、歌曲名s2输出。分三种情况：
// 如果s1指定的歌手不存在，则输出：
// Singer $ doesn't exist.
// 如果s1存在，但是该歌手没有演唱s2指定的歌曲，则输出：
// $ doesn’t sing %.
// 如果s1、s2能够确定某首歌曲，则输出：
// $ sings % in # style.
// 上述$、#和%的含义同前。
//
// Input
// 输入分为2部分。
// 第1部分是按照SingerList类的要求输入的歌手及歌曲信息。
// 第2部分也有多行，每行包括2个字符串，分别是指定的歌手名和歌曲名。
// 假定所有的歌手名、歌曲名均不相同。
//
// Output
// 见样例。

// Sample Input
// 3
// Tom 4 1 ChangJiu 2 DuanZan 3 Main 1 Object
// Jack 1 1 Output
// Mary 2 1 Input 3 GCC
// Tom DuanZan
// Jack Input
// Mary GCC
// CUI BIGDATA

// Sample Output
// In beginning, there are 0 singers, and 0 songs.
// LiuHuan sings XiongDi in popular style.
// LiuHuan sings SanGuo in folk style.
// LiuHuan sings SongBie in Bel Canto style.
// LiuHuan doesn't sing MeiYou.
// Tom : ChangJiu DuanZan Main Object
// Jack : Output
// Mary : Input GCC
// Now, there are 4 singers, and 10 songs. Including 5 pop songs, 2 folk songs, and 3 Bel Canto songs.
// Tom sings DuanZan in folk style.
// Jack doesn't sing Input.
// Mary sings GCC in Bel Canto style.
// Singer CUI doesn't exist.

#include <iostream>
#include <string>
#include <vector>
using namespace std;
 
struct Song {
  string title;
  int style; // 1: Pop, 2: Folk, 3: Bel Canto
  static int cnt;
  Song(string t, int tp) : title(t), style(tp) {
    cnt++;
  }
  static int getCntOfSongs() {
    return cnt;
  }
};
int Song::cnt = 0;
 
struct Pop : Song {
  static int cnt;
  Pop(string t) : Song(t, 1) {
    cnt++;
  }
  static int getCntOfPops() {
    return cnt;
  }
};
int Pop::cnt = 0;
 
struct Folk : Song {
  static int cnt;
  Folk(string t) : Song(t, 2) {
    cnt++;
  }
  static int getCntOfFolks() {
    return cnt;
  }
};
int Folk::cnt = 0;
 
struct Bel : Song {
  static int cnt;
  Bel(string t) : Song(t, 3) {
    cnt++;
  }
  static int getCntOfBels() {
    return cnt;
  }
};
int Bel::cnt = 0;
 
struct Singer {
  string name;
  vector<Song *> songs;
  static int cnt;
  Singer(string n) : name(n) {
    cnt++;
  }
 
  static int getCntOfSingers() {
    return cnt;
  }
 
  void addASong(string title, int type) {
    Song *s = 0;
    if (type == 1)
      s = new Pop(title);
    else if (type == 2)
      s = new Folk(title);
    else if (type == 3)
      s = new Bel(title);
    if (s)
      songs.push_back(s);
  }
 
  Song *findSong(const string &title) {
    for (size_t i = 0; i < songs.size(); ++i) {
      if (songs[i]->title == title)
        return songs[i];
    }
    return 0;
  }
 
  void singASong(string title) {
    Song *s = findSong(title);
    if (!s) {
      cout << name << " doesn't sing " << title << "." << endl;
      return;
    }
    cout << name << " sings " << title << " in "
         << (s->style == 1   ? "popular"
             : s->style == 2 ? "folk"
                             : "Bel Canto")
         << " style." << endl;
  }
};
int Singer::cnt = 0;
 
struct SingerList {
  vector<Singer *> singers;
 
  Singer *findSinger(const string &name) {
    for (size_t i = 0; i < singers.size(); ++i) {
      if (singers[i]->name == name)
        return singers[i];
    }
    return 0;
  }
 
  friend istream &operator>>(istream &is, SingerList &l) {
    int n;
    is >> n;
    for (int i = 0; i < n; ++i) {
      string name;
      is >> name;
      Singer *s = new Singer(name);
      l.singers.push_back(s);
      int m;
      is >> m;
      for (int j = 0; j < m; ++j) {
        int type;
        string title;
        is >> type >> title;
        s->addASong(title, type);
      }
    }
    return is;
  }
 
  friend ostream &operator<<(ostream &os, const SingerList &l) {
    for (size_t i = 0; i < l.singers.size(); ++i) {
      os << l.singers[i]->name << " :";
      for (size_t j = 0; j < l.singers[i]->songs.size(); ++j) {
        os << " " << l.singers[i]->songs[j]->title;
      }
      os << endl;
    }
    return os;
  }
 
  void Choose(string s1, string s2) {
    Singer *s = findSinger(s1);
    if (!s) {
      cout << "Singer " << s1 << " doesn't exist." << endl;
      return;
    }
    s->singASong(s2);
  }
};

// Append Code
int main()
{
    cout<<"In beginning, there are ";
    cout<<Singer::getCntOfSingers()<<" singers, and ";
    cout<<Song::getCntOfSongs()<<" songs."<<endl;
    Singer liuh("LiuHuan");
    liuh.addASong("XiongDi", 1);
    liuh.addASong("SanGuo", 2);
    liuh.addASong("SongBie", 3);
    liuh.singASong("XiongDi");
    liuh.singASong("SanGuo");
    liuh.singASong("SongBie");
    liuh.singASong("MeiYou");
 
    SingerList lst;
    string s1, s2;
    cin>>lst;
    cout<<lst;
    cout<<"Now, there are ";
    cout<<Singer::getCntOfSingers()<<" singers, and ";
    cout<<Song::getCntOfSongs()<<" songs. Including ";
    cout<<Pop::getCntOfPops()<<" pop songs, ";
    cout<<Folk::getCntOfFolks()<<" folk songs, and ";
    cout<<Bel::getCntOfBels()<<" Bel Canto songs."<<endl;
    while(cin>>s1>>s2)
    {
        lst.Choose(s1, s2);
    }
    return 0;
}
