#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;

ll modpow(ll x, ll n, ll mod = MOD) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    string s;
    cin >> n >> s;

    ll ans = 1;
    ll cnt = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (cnt % 2 == 0) {
            if (s[i] == 'W') {
                if (cnt == 0) {
                    ans = 0;
                    break;
                }

                (ans *= cnt) %= MOD;
                cnt--;
            } else {
                cnt++;
            }
        } else {
            if (s[i] == 'W') {
                cnt++;
            } else {
                if (cnt == 0) {
                    ans = 0;
                    break;
                }

                (ans *= cnt) %= MOD;
                cnt--;                
            }
        }
    }

    if (ans == 0 || cnt > 0) {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        (ans *= i) %= MOD;
    }
    cout << ans << endl;
    return 0;
}
