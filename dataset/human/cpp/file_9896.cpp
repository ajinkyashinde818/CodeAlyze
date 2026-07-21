#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using piii = pair<int, pair<int, int>>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
template <typename T>
using Graph = vector<vector<T>>;
const int MOD = 1e9 + 7;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> cnt(26, 1);
    for (int i = 0; i < N; ++i) {
        char c;
        cin >> c;
        cnt[c - 'a']++;
    }

    ll ans = 1;
    for (auto i : cnt)
        (ans *= i) %= MOD;
    ans--;
    if (ans < 0)
        ans += MOD;

    cout << ans << endl;
    return 0;
}
