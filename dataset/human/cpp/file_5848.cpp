#include <algorithm>
#include <iostream>
#include <cstdio>
#include <map>
#include <numeric>
#include <cmath>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <complex>
#include <string.h>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <iomanip>
#include <sys/time.h>
#include <tuple>
#include <random>
using namespace std;

#define endl '\n'
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define UNIQ(v) (v).erase(unique((v).begin(), (v).end()), (v).end())

typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef complex<double> comp;
typedef vector< vector<ld> > matrix;
struct pairhash {
public:
    template<typename T, typename U>
    size_t operator()(const pair<T, U> &x) const {
	size_t seed = hash<T>()(x.first);
	return hash<U>()(x.second) + 0x9e3779b9 + (seed<<6) + (seed>>2);
    }
};
const int inf = 1e9 + 9;
const ll mod = 1e9 + 7;
const double eps = 1e-8;
const double pi = acos(-1);

int n;
ll C;
ll x[100100];
ll v[100100];

ll sum[2][100100];
ll best[2][100100];

ll solve() {
    ll res = 0;
    ll val = 0;
    ll best0 = -1e18;
    for (int i = 1; i <= n; i++) {
        val += v[i];
        val -= (x[i] - x[i-1]);
        sum[0][i] = val;
        best0 = max(best0, val);
        res = max(res, val);
    }
    val = 0;
    ll best1 = -1e18;
    for (int i = n; i >= 1; i--) {
        val += v[i];
        val -= (x[i+1] - x[i]);
        sum[1][i] = val;
        best1 = max(best1, val);
        res = max(res, val);
    }

    for (int i = 1; i <= n; i++) {
        if (best[0][i-1] < sum[0][i]) {
            best[0][i] = sum[0][i];
        } else {
            best[0][i] = best[0][i-1];
        }
    }
    for (int i = n; i >= 1; i--) {
        if (best[1][i+1] < sum[1][i]) {
            best[1][i] = sum[1][i];
        } else {
            best[1][i] = best[1][i+1];
        }
    }
    
    for (int i = 1; i <= n; i++) {
        res = max(res, sum[0][i] - x[i] + best[1][i+1]);
    }
    for (int i = n; i >= 1; i--) {
        res = max(res, sum[1][i] - (C-x[i]) + best[0][i-1]);
    }
    return res;
}

void input() {
    cin >> n >> C;
    x[0] = v[0] = 0;
    for (int i = 0; i < n; i++) cin >> x[i+1] >> v[i+1];
    x[n+1] = C;
    v[n+1] = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);

    input();
    cout << solve() << endl;
}
