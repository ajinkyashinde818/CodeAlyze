#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;
using P = pair<int, int>;
constexpr ld EPS = 1e-12;
constexpr int INF = numeric_limits<int>::max() / 2;
constexpr int MOD = 1e9 + 7;

template <typename T>
void printv(const vector<T> &v)
{
    int sz = v.size();
    for (int i = 0; i < sz; i++)
    {
        cout << v[i] << " \n"[i == sz - 1];
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> cnt(26, 0);
    for (int i = 0; i < n; i++)
    {
        cnt[s[i] - 'a']++;
    }
    ll ret = 1;
    for (int i = 0; i < 26; i++)
    {
        ret *= (cnt[i] + 1);
        ret %= MOD;
    }
    ret = (ret + MOD - 1) % MOD;
    cout << ret << endl;
}
