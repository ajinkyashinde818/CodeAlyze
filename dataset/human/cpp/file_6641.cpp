#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll mod = 1e9 + 7;

ll sum(ll a, ll b) { return (a + b) % mod; }
void add(ll& a, ll b) { a = sum(a, b); }
ll sub(ll a, ll b) { return (a - b + mod) % mod; }
ll mul(ll a, ll b) { return a * b % mod; }

void NO() {
    cout << 0 << endl;
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(false);
    ll n;
    string s;
    cin >> n >> s;
    ll cur = 0;
    ll ans(1);
    for (char c : s)
        if (c == 'W') {
            if (cur % 2)
                ++cur;
            else if (cur == 0)
                NO();
            else {
                ans = mul(ans, cur);
                --cur;
            }
        } else {
            if (cur % 2) {
                ans = mul(ans, cur);
                --cur;
            } else {
                ++cur;
            }
        }
    if (cur) NO();
    for (int i(1); i <= n; ++i)
        ans = mul(ans, i);
    cout << ans << endl;
}
