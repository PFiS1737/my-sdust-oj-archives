// Description
// 定义函数
// char next(char ch);
// 求英文字母ch的下一个字母。其中ch是一个英文字母，如果ch是小写字母z或者大写字母Z，则返回a或者A。
//
// Input
// 输入分2行，第一行是一个正整数m，表示后面有m个英文字母。
// 第2行是m个英文字母。
//
// Output
//
// 输出m个英文字母，每个输入对应一个输出。

// Sample Input
// 4
// AbZc

// Sample Output
// BcAd

#include <cstdio>

char next(char ch) {
  if (ch == 'z')
    return 'a';
  if (ch == 'Z')
    return 'A';
  return ch + 1;
}

// Append Code Start
int main()
{
    int m, i;
    char ch;
    scanf("%d",&m);
    getchar();
    for(i=0;i<m;i++){
        ch=getchar();
        putchar(next(ch));
    }
    return 0;
}
// Append Code End
