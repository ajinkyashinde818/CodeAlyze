#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;
    int n = 0, p = 0;
    bool inf = false;
    int pcnt = str.find('.'), cnt = 0;
    int cnt2 = 0;
    for(int i=0; i<str.size(); ++i) {
        inf |= str[i] == '(';
        if(isdigit(str[i])) {
            n *= 10;
            n += str[i] - '0';
            if(!inf) {
                p *= 10;
                p += str[i] - '0';
            }
            cnt++;
            cnt2 += inf;
        }
    }
    cnt -= pcnt;
    if(inf) {
        n -= p;
    }
    int del = pow(10, cnt) - (inf ? pow(10, cnt-cnt2) : 0);
    int g = __gcd(n, del);
    n /= g;
    del /= g;
    cout << n << '/' << del << endl;
}
