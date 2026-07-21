#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;

int main() {
    ll n, ans, l, r;
    string s;
    cin >> n >> s;
    if (s[0] == 'W') {
        cout << 0 << endl;
        return 0;
    }
    ans = 1;
    l = 1, r = 2 * n - 1;
    for (int i = 1; i < 2 * n; i++) {
        if (s[i] == 'B') {
            if (l % 2) {
                ans = (ans * l) % mod;
                l--;
            } else {
                l++;
            }
        } else {
            if (l % 2) {
                l++;
            } else {
                ans = (ans * l) % mod;
                l--;
            }
        }
        r--;
    }
    if (l != 0 || r != 0) {
        cout << 0 << endl;
        return 0;
    }
    for (ll i = n; i >= 1; i--) {
        ans = ans * i % mod;
    }
    cout << ans << endl;
    return 0;
}
