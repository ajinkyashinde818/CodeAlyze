#include "bits/stdc++.h"

using namespace std;

using ll = long long;

template<typename T> using V = std::vector<T>;
using Vi = V<int>;
using VVi = V<V<int>>;
using Vl = V<ll>;
using VVl = V<V<ll>>;
using Vs = V<string>;

template<typename T1, typename T2> using P = std::pair<T1, T2>;
using Pii = P<int, int>;
using Pll = P<ll, ll>;
using Pdd = P<double, double>;

template<typename T1, typename T2> using M = std::map<T1, T2>;
using Mii = M<int, int>;
using Msi = M<string, int>;

#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define REP2(i,s,e) for(int i=(int)(s);i<(int)(e);++i)
#define RREP(i,s,e) for(int i=(int)(s);i>=(int)(e);--i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin(),ie=(c).end();i!=ie;++i)
#define ALL(c) (c).begin(), (c).end()

const double PI = acos(-1);
const ll MOD = 1e9+7;


int n, m;
string s;

int main() {
    cin >> n;

    Vi v(n);
    REP(i, n) cin >> v[i];

    int cnt = 0;
    int absmin = 1e9;
    ll sum = 0;
    REP(i, n) {
        if (v[i] < 0) cnt++;
        if (abs(v[i]) < absmin) absmin = abs(v[i]);
        sum += abs(v[i]);
    }

    if (cnt%2 == 0) {
        std::cout << sum << '\n';
    } else {
        std::cout << sum - absmin*2 << '\n';
    }

    return 0;
}
