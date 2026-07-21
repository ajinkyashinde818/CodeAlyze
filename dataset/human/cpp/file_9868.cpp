#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int main() {

    int n; cin >> n;
    string s; cin >> s;

    vector<ll> num(30, 0);
    for (auto c : s) {
        num[c - 'a']++;
    }

    ll ans = 1;
    for (int i = 0; i < 26; ++i) {
        ans *= num[i] + 1;
        ans %= MOD;
    }

    ans -= 1;

    cout << ans << endl;
}
