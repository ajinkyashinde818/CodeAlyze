#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll mod = 1e9 + 7;

int main() {
    int n; cin >> n;
    string s; cin >> s;

    ll ans = 1, remain = 0;
    for(int i = 0; i < 2 * n; ++i) {
        if(i & 1) {
            if(s[i] == 'W') { // must right
                remain += 1;
            } else {
                if(remain == 0) ans = 0;
                (ans *= remain) %= mod;
                remain--;
            }
        } else {
            if(s[i] == 'W') { // must left
                if(remain == 0) ans = 0;
                (ans *= remain) %= mod;
                remain--;
            } else {
                remain += 1;
            }
        }
    }

    if(remain != 0) ans = 0;
    for(int i = 1; i <= n; ++i) {
        (ans *= i) %= mod;
    }
    cout << ans << endl;
}
