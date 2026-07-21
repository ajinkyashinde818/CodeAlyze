#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
#include <stack>
#include <functional>

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...)
#endif

#define rep_(i, a_, b_, a, b, ...) for (int i = (a), i##_len = (b); i < i##_len; ++i)
#define rep(i, ...) rep_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
#define reprev_(i, a_, b_, a, b, ...) for (int i = (b-1), i##_min = (a); i >= i##_min; --i)
#define reprev(i, ...) reprev_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
#define all(x) (x).begin(), (x).end()
template <class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template <class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }
#define fls(x) (64 - __builtin_clzll(x))
#define pcnt(x) __builtin_popcountll(x)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> P;
typedef long double ld;

vector<vector<int>> ans;
void rec (ll m, ll mstart, ll k, ll kstart) {
    eprintf("%lld %lld %lld %lld\n", m, mstart, k, kstart);
    if (m <= 0) return;
    rep (i, m) {
        ans[kstart].push_back(mstart + i);
        ans[kstart + i + 1].push_back(mstart + i);
    }
    rec(m - 1, mstart + m, k - 1, kstart + 1);
}

int main (void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    ll ng = 0, ok = n;
    while (ok - ng > 1) {
        ll med = (ok + ng) / 2;
        if (med * (med + 1) / 2 >= n) ok = med;
        else ng = med;
    }
    if (ok * (ok + 1) / 2 != n) {
        cout << "No\n"; return 0;
    }
    ll m = ok, k = ok + 1;
    ans.resize(k);
    rec(m, 1, k, 0);
    cout << "Yes\n" << k << "\n";
    rep (i, k) {
        cout << m << " ";
        rep (j, ans[i].size()) cout << ans[i][j] << " \n"[j + 1 == j_len];
    }
    return 0;
}
