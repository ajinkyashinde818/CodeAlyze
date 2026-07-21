#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1000000007;

using Long = long long;
template<typename T>
using V = vector<T>;
template<typename T>
using Vv = V<V<T>>;
using Vb = V<bool>;
using Vvb = V<Vb>;
using Vi = V<int>;
using Vvi = V<Vi>;
using Vl = V<Long>;
using Vvl = V<Vl>;
using Vd = V<double>;
using Vvd = V<Vd>;
using Vs = V<string>;

template <typename First, typename Second>
istream& operator>>(istream& is, pair<First, Second>& v);

template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
    for (auto& x : v) {
        is >> x;
    }
    return is;
}

template <typename First, typename Second>
istream& operator>>(istream& is, pair<First, Second>& v) {
    is >> v.first >> v.second;
    return is;
}

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (const auto& x : v) {
        os << x << ' ';
    }
    return os;
}

// *** SOLUTION BEGIN ***

void solve() {
    int n;
    Long c;
    cin >> n >> c;
    V<pair<Long, int>> s(n);
    cin >> s;

    vector<Long> pos(n + 1);
    vector<Long> neg(n + 1);
    Long cur = 0;
    Long x = 0;
    for (int i = 0; i < n; ++i) {
        cur += s[i].second - (s[i].first - x);
        pos[i + 1] = max(pos[i], cur);
        x = s[i].first;
    }
    cur = 0;
    x = c;
    for (int i = n - 1; i >= 0; --i) {
        cur += s[i].second - (x - s[i].first);
        neg[i] = max(neg[i + 1], cur);
        x = s[i].first;
    }
    Long best = max(pos[n], neg[0]);
    cur = 0;
    x = 0;
    for (int i = 0; i < n; ++i) {
        cur += s[i].second - 2 * (s[i].first - x);
        best = max(best, cur + neg[i + 1]);
        x = s[i].first;
    }
    cur = 0;
    x = c;
    for (int i = n - 1; i >= 0; --i) {
        cur += s[i].second - 2 * (x - s[i].first);
        best = max(best, cur + pos[i]);
        x = s[i].first;
    }
    cout << best;
}

// *** SOLUTION END ***

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    solve();
    return 0;
}
