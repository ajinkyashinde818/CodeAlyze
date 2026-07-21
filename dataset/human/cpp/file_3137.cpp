// {{{
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
// }}}

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

static constexpr int mod = (int)1e9 + 7;
static constexpr int inf = 100100100;
static constexpr ll linf = 1e18;
static constexpr double eps = 1e-9;
static constexpr double pi = 3.14159265359;

#define rep(i, n) for (ll i = 0; i < n; ++i)
#define rrep(i, n) for (ll i = n; i >= 0; --i)
#define all(c) begin(c), end(c)
#define rall(c) rbegin(c), rend(c)
#define pb push_back
#define ist insert
#define fst first
#define snd second



int main() {
    // cin.tie(0);
    // ios_base::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> A;
    rep (i, N) {
        ll a;
        cin >> a;
        A.pb(a);
    }
    ll a0 = A[0] + A[1];
    ll a1 = -a0;
    for (ll i = 1; i < N - 1; ++i) {
        ll a00 = a0 + A[i + 1];
        ll a01 = a0 - 2 * A[i] - A[i + 1];
        ll a10 = a1 + A[i + 1];
        ll a11 = a1 + 2 * A[i] - A[i + 1];
        a0 = max(a00, a10);
        a1 = max(a01, a11);
    }
    cout << max(a0, a1) << endl;
}
