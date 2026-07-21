#include <iostream>
#include <cstdio>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cctype>
#include <stack>
#include <bitset>
#include <unordered_set>
#include <map>
#include <set>
#include <cmath>
//#include <bits/stdc++.h>

using namespace std;
typedef long long lolo;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef unsigned long long ulolo;

const int maxn = (int)1e5 + 5;
const lolo maxx = (lolo)10000001;
const int maxm =(int)2e3 + 5;
const int INF = 0x3f3f3f3f;
const lolo inf = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-6;
const int MOD = (int)1e6 + 3;

template<class T>
inline void read(T &x) {
    x = 0; T flag = 1;char c;
    do { c = (char) getchar(); if (c == '-') break; } while (c < '0' || c > '9');
    if (c == '-') { c = '0', flag = -1;}
    do { x = x * 10 + c - '0';c = (char) getchar();} while (c >= '0' && c <= '9');
    x *= flag;
}
template<class T>
inline void out(T x) {
    if (x > 9) out(x / 10);
    x = x % 10;
    putchar('0' + x);
}

int a[maxn];
int main() {
//    freopen("../in.txt", "r", stdin);
    int n;
    read(n);
    int cnt = 0, Min = INF;
    lolo ans = 0;
    for (int i = 1; i < n+1; ++i) {
        read(a[i]);
        if (a[i] < 0) {
            ++cnt;
        }
        Min = min(Min, abs(a[i]));
        ans += abs(a[i]);
    }
    if (cnt%2==1) {
        ans -= 2*Min;
    }
    printf("%lld\n", ans);
    return 0;
}
