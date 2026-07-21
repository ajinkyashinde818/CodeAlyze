#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using WGraph = vector<vector<pair<int, ll>>>;

template<class T>inline bool chmax(T &a, const T &b) { if (b > a) { a = b; return true; } return false; }
template<class T>inline bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

constexpr int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;
constexpr long long LINF = 1e18;
constexpr double EPS = 1e-10;
constexpr double PI = M_PI;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    if (s.front() == 'W' || s.back() == 'W') {
        cout << 0 << '\n';
        return;
    }
    int L = 0, R = 0;
    ll res = 1;
    for (int i=0; i<2*n; ++i) {
        if (i == 0 || s.at(i) != s.at(i-1)) {
            ++L;
        } else {
            res *= L - R;
            res %= MOD;
            ++R;
            s.at(i) = s.at(i) == 'W' ? 'B' : 'W';
        }
    }
    if (L != R) {
        cout << 0 << '\n';
    } else {
        for (int i=1; i<=n; ++i) {
            res *= i;
            res %= MOD;
        }
        cout << res << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
