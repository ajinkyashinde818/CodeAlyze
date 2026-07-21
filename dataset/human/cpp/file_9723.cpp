#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;

const ll MOD = (ll) 1e9 + 7;

int main() {
    int n;
    string s;
    cin >> n >> s;

    map<int, ll> mp;
    for (int i = 0; i < n; ++i) {
        ++mp[s[i] - 'a'];
    }

    ll ans = 1;
    for (auto i : mp) {
        (ans *= (i.second + 1)) %= MOD;
    }

    cout << ans - 1 << endl;
}
