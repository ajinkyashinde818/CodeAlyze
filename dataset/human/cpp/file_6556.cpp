//#pragma GCC optimize("O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(n * 2);
    for (int i = 0; i < n * 2; i++) {
        a[i] = (s[i] == 'B') ^ (i & 1);
    }
    //1 = r, 0 = l
    int cnt = 0;
    ll ans = 1;
    for (int i = 0; i < n * 2; i++) {
        cnt += a[i];
        if (a[i] == 0) {
            (ans *= cnt) %= mod;
            cnt--;
        }
    }
    for (int i = 2; i <= n; i++) {
        (ans *= i) %= mod;
    }
    if (cnt) {
        ans = 0;
    }
    cout << ans;
    return 0;
}
