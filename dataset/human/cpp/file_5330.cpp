#include <bits/stdc++.h>
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (b>a) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const long long INF = 2LL << 60;
using ll = long long;
using P = pair<string, ll>;



int main(int argc, char const *argv[]) {
    ll n, r;
    cin >> n >> r;
    if (n < 10) r +=100 *(10 - n);
    cout << r << endl;
    return 0;
}
