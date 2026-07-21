#include <iostream>
#include <fstream>
#include <iomanip>
#include <climits>
#include <limits>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <stack>
#include <string>
#include <functional>
#include <numeric>
#include <map>
#include <set>
#include <cstdlib>
#include <bitset>
#include <unordered_map>
#include <random>
#include <cmath>
#include <complex>

using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;

const int INFL = (int)1e9;
const ll INFLL = (ll)1e18;
const double INFD = numeric_limits<double>::infinity();
const double PI = 3.14159265358979323846;
#define Loop(i, n) for(int i = 0; i < (int)n; i++)
#define Loopll(i, n) for(ll i = 0; i < (ll)n; i++)
#define Loop1(i, n) for(int i = 1; i <= (int)n; i++)
#define Loopll1(i, n) for(ll i = 1; i <= (ll)n; i++)
#define Loopr(i, n) for(int i = (int)n - 1; i >= 0; i--)
#define Looprll(i, n) for(ll i = (ll)n - 1; i >= 0; i--)
#define Loopr1(i, n) for(int i = (int)n; i >= 1; i--)
#define Looprll1(i, n) for(ll i = (ll)n; i >= 1; i--)
#define Loopitr(itr, container) for(auto itr = container.begin(); itr != container.end(); itr++)
#define printv(vector) Loop(i, vector.size()) { cout << vector[i] << " "; } cout << endl;
#define rnd(d) (ll)((double)d + (d >= 0 ? 0.5 : -0.5))
#define floorsqrt(x) ((ll)sqrt((double)x) + ((ll)sqrt((double)x) * (ll)sqrt((double)x) <= (ll)x ? 0 : -1))
#define ceilsqrt(x) ((ll)sqrt((double)x) + ((ll)x <= (ll)sqrt((double)x) * (ll)sqrt((double)x) ? 0 : 1))
#define ceildiv(a, b) ((ll)a / (ll)b + ((ll)a % (ll)b == 0 ? 0 : 1))
#define bitmanip(m,val) static_cast<bitset<(int)m>>(val)

/*******************************************************/

struct sushi {
	ll x;
	ll v;
};

int main() {
	int n; cin >> n;
	ll c; cin >> c;
	vector<vector<sushi>> a(2, vector<sushi>(n));
	Loop(i, n) {
		cin >> a[0][i].x >> a[0][i].v;
	}
	Loopr(i, n) {
		a[1][n - 1 - i].x = c - a[0][i].x;
		a[1][n - 1 - i].v = a[0][i].v;
	}
	vvll dat(2, vll(n + 1, 0));
	Loop(k, 2) {
		Loop(i, n) {
			ll pre_x = i > 0 ? a[k][i - 1].x : 0;
			dat[k][i + 1] = dat[k][i] + a[k][i].v - (a[k][i].x - pre_x);
		}
	}
	vvll max_dat(2, vll(n + 1, 0));
	Loop(k, 2) {
		Loop(i, n) {
			max_dat[k][i + 1] = max(max_dat[k][i], dat[k][i + 1]);
		}
	}
	ll ans = 0;
	Loop(k, 2) {
		Loop(i, n) {
			ll buf1 = dat[k][i + 1];
			ll buf2 = dat[k][i + 1] - a[k][i].x + max_dat[(k + 1) % 2][n - 1 - i];
			ans = max(ans, max(buf1, buf2));
		}
	}
	cout << ans << endl;
}
