// INFO: 💩
//
// Description
// 银行（Bank）是由若干个账户（Account）组成的，定义Account类模拟账户，包括：
// 1.账户名、密码和金额三个属性，前两个是不含空白符的字符串，金额是实数。
// 2.恰当的构造函数。
// 3.成员函数getName()、getPasswd()、getMoney()用于返回账户名、账户密码和当前余额。
// Bank类由若干个账号组成，包括如下成员函数：
// 1.addAccount(Account&)：增加一个账户。如果已有重名账户，则提示“Repeated account.”，否则追加一个新账户。
// 2.getTotalMoney()：获取当前账户中的总余额。
// 3. getCntAccounts()：获取当前的账户个数。
// 4. withdraw(string n, string p, double m)：给定账户名n、密码p，取出金额m。如果没有账户名n，则提示“No matching account.”；如果有该账户名，但是密码错误，则提示“Password is wrong.”；如果n、p都正确，但是该账户余额不足，则提示“Money is not enough.”；否则取出相应金额，并按照样例提示取款成功。
// 5. deposit(string n, string p, double m)：给定账户n、密码p，存放金额m。如果没有账户名n，则提示“No matching account.”；如果有该账户名，但是密码错误，则提示“Password is wrong.”；否则存入相应金额，并按照样例提示存款成功。
//
// Input
// 输入有多行。第一行是一个正整数N，表示后面输入N个账户的信息。
// 后面的N行，每行包括1个账户名、1个密码和1个当前余额。前两个是不含空白符的字符串，最后一个是一个实数。
// 之后的若干行，每行开头是一个字母“w”（表示取款）或“d”（表示存款），接着是操作的账户名、密码，最后是操作的金额。
//
// Output
// 见样例。

// Sample Input
// 3
// Jack 314134 10000
// Mary 103465 20000
// Jack 214133 10000
// w Jack 30000 1000
// w Jccc 333333 1000
// w Jack 314134 1000
// d Mary 103456 2000
// d Marr 303023 2001
// d Mary 103465 2000
// w Jack 314134 20000

// Sample Output
// Test 66666 0
// test 111111 0
// test3 222222 10000
// Repeated account.
// There are 2 accounts, and the total money is 30000.
// Password is wrong.
// No matching account.
// Withdraw 1000 successful.
// Password is wrong.
// No matching account.
// Deposit 2000 successful.
// Money is not enough.
// Now, there are 2 accounts, and the total money is 31000.

#include <iostream>
#include <vector>
using namespace std;
 
struct Account {
  string name, passwd;
  double money;
  Account(const string &n = "", const string &p = "66666", double m = 0.0)
      : name(n), passwd(p), money(m) {
  }
  string getName() const {
    return name;
  }
  string getPasswd() const {
    return passwd;
  }
  double getMoney() const {
    return money;
  }
};
 
struct Bank {
  vector<Account> accounts;
  void addAccount(const Account &acc) {
    for (size_t i = 0; i < accounts.size(); i++) {
      if (accounts[i].getName() == acc.getName()) {
        cout << "Repeated account." << endl;
        return;
      }
    }
    accounts.push_back(acc);
  }
  int getCntAccounts() const {
    return accounts.size();
  }
  double getTotalMoney() const {
    double total = 0;
    for (size_t i = 0; i < accounts.size(); i++) {
      total += accounts[i].getMoney();
    }
    return total;
  }
  void withdraw(const string &name, const string &passwd, double money) {
    for (size_t i = 0; i < accounts.size(); i++) {
      if (accounts[i].getName() == name) {
        if (accounts[i].getPasswd() == passwd) {
          if (accounts[i].getMoney() >= money) {
            accounts[i].money -= money;
            cout << "Withdraw " << money << " successful." << endl;
          } else {
            cout << "Money is not enough." << endl;
          }
        } else {
          cout << "Password is wrong." << endl;
        }
        return;
      }
    }
    cout << "No matching account." << endl;
  }
  void deposit(const string &name, const string &passwd, double money) {
    for (size_t i = 0; i < accounts.size(); i++) {
      if (accounts[i].getName() == name) {
        if (accounts[i].getPasswd() == passwd) {
          accounts[i].money += money;
          cout << "Deposit " << money << " successful." << endl;
        } else {
          cout << "Password is wrong." << endl;
        }
        return;
      }
    }
    cout << "No matching account." << endl;
  }
};
 
// Append Code
int main()
{
    const Account acc1("Test"), acc2("test","111111"),acc3("test3","222222",10000);
    cout<<acc1.getName()<<" "<<acc1.getPasswd()<<" "<<acc1.getMoney()<<endl;
    cout<<acc2.getName()<<" "<<acc2.getPasswd()<<" "<<acc2.getMoney()<<endl;
    cout<<acc3.getName()<<" "<<acc3.getPasswd()<<" "<<acc3.getMoney()<<endl;
    Bank bank;
    int n;
    string name, passwd;
    double money;
    char ch;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>name>>passwd>>money;
        Account acc(name,passwd,money);
        bank.addAccount(acc);
    }
    cout<<"There are "<<bank.getCntAccounts()<<" accounts,";
    cout<<" and the total money is "<<bank.getTotalMoney()<<"."<<endl;
    while(cin>>ch)
    {
        cin>>name>>passwd>>money;
        switch(ch)
        {
        case 'w':
            bank.withdraw(name,passwd,money);
            break;
        case 'd':
            bank.deposit(name,passwd,money);
            break;
        }
    }
    cout<<"Now, there are "<<bank.getCntAccounts()<<" accounts,";
    cout<<" and the total money is "<<bank.getTotalMoney()<<"."<<endl;
    return 0;
}
