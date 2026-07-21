// https://atcoder.jp/contests/abcXXX/tasks/abcXXX_x

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;

static const ll INF = 1001001001;
static const ll LLINF = 1001001001001001001;

#define REP(i, n) for(ll i = 0; i < (n); ++i)
#define RANGE(i, m, n) for(ll i = (m); i <= (n); ++i)
#define RRANGE(i, m, n) for(ll i = (m); i >= (n); --i)
#define POSITIVE(x) (x)=((x) < 0) ? 0 : (x)

ll pow(ll x, ll y) {
    ll ret = 1;
    while(y-- > 1) ret *= x;
    return ret;
}

ll gcd(ll x, ll y) {
    if (x < y) swap(x, y);
    if (y == 0) return x;
    ll r = x / y;
    return gcd(y, x-y*r);
}

int run(istream& in, ostream& out) {
    ll N,R ;
    in >> N >> R;
    ll ans = 0;
    ans = R;
    if (N < 10) {
        ans = R + 1000 - 100 * N;
    }
    out << ans << endl;
    return 0;
}

int main() {
    return run(cin, cout);
}
