#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<queue>
#include<stack>
#include<bitset>
#include<functional>
#include<map>
#include<iomanip>
#include<limits>
#include<unordered_set>
#include<cmath>
#include <numeric>
#include <array>
#include <complex>
using namespace std;
//long long p = 998244353;
long long p = 1000000007;
#define int long long
#define ll long long
#define vel vector<ll>
#define vvel vector<vel>
#define rep(i,n) for(int i=0;i<n;i++)
#define sor(v) sort(v.begin(),v.end())
#define mmax(a,b) a=max(a,b)
#define mmin(a,b) a=min(a,b)
#define mkp make_pair
#define pin pair<int,int>
#define qin pair<pin,int>
#define V vector
#define Endl endl
#define veb vector<bool>
#define fcout cout << fixed << setprecision(15)
#define rev(s) reverse(s.begin(),s.end())
#define lower(h,val) lower_bound(h.begin(),h.end(),val)-h.begin()
#define upper(h,val) upper_bound(h.begin(),h.end(),val)-h.begin()
vel kai;
vel inv_kai;
int rui(int a, int n, int mod) {
	if (n == 0) { return 1 % mod; }
	int x = rui(a, n / 2, mod);
	x *= x; x %= mod;
	if (n % 2 == 1) { x *= a; x %= mod; }
	return x;
}
int root(int x, vel& pa) {
	if (pa[x] == -1) { return x; }
	int ans = root(pa[x], pa); pa[x] = ans;
	return ans;
}
bool mar(int x, int y, vel& pa) {
	x = root(x, pa);
	y = root(y, pa);
	if (x != y) { pa[x] = y; }
	return (x != y);
}
int gcd(int x, int y) {
	if (x < y) { return gcd(y, x); }
	if (y == 0) { return x; }
	return gcd(y, x % y);
}
int lcm(ll x, ll y) {
	x = abs(x); y = abs(y);
	return x * y / gcd(x, y);
}
long long modinv(long long a, long long m) {
	long long b = m, u = 1, v = 0;
	while (b) {
		long long t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= m;
	if (u < 0) u += m;
	return u;
}
void make_kai(int max_kai) {
	kai = vel(max_kai, 1);
	inv_kai = kai;
	rep(i, max_kai - 1) {
		kai[i + 1] = kai[i] * (i + 1); kai[i + 1] %= p;
		inv_kai[i + 1] = modinv(kai[i + 1], p);
	}
}
int com(int n, int r) {
	if ((n < 0) || (r < 0) || (r > n)) { return 0; }
	int ans = (kai[n] * inv_kai[r]) % p;
	return (ans * inv_kai[n - r]) % p;
}
vel uni(vel x) {
	if (x.size() == 0) { return x; }
	sor(x);
	int n = x.size();
	vel ans(1, x[0]);
	for (int j = 1; j < n; j++) {
		if (x[j - 1] != x[j]) { ans.push_back(x[j]); }
	}
	x = ans;
	return x;
}
void pr(vel& v) {
	int n = v.size();
	if (n != 0) {
		cout << v[0];
		rep(i, n - 1) {
			cout << " " << v[i + 1];
		}
		cout << endl;
	}
}
vel dijk(V<V<pin>>& way, int st, int inf) {
	int n = way.size();
	vel dist(n, inf); dist[st] = 0;
	priority_queue<pin, vector<pin>, greater<pin>> pq;
	pq.push(mkp(0, st));
	veb is_checked(n, false);
	while (!pq.empty()) {
		pin x = pq.top(); pq.pop();
		int pot = x.second;
		if (!is_checked[pot]) {
			is_checked[pot] = true;
			for (auto y : way[pot]) {
				int nex_dist = x.first + y.second;
				int nex_pot = y.first;
				if (dist[nex_pot] > nex_dist) {
					dist[nex_pot] = nex_dist;
					pq.push(mkp(nex_dist, y.first));
				}
			}
		}
	}
	return dist;
}
vel mul(vel& a, vel& b) {
	int n = a.size();
	int m = b.size();
	vel ans(n + m - 1, 0);
	rep(i, n) {
		rep(j, m) {
			ans[i + j] += a[i] * b[j];
			ans[i + j] %= p;
		}
	}
	return ans;
}
vel rui_p(vel& a, int n) {
	if (n == 0) { return { 1 }; }
	vel qans = rui_p(a, n / 2);
	qans = mul(qans, qans);
	if (n % 2 == 1) {
		qans = mul(qans, a);
	}
	return qans;
}
bool is_prime(int n) {
	if (n == 0 || n == 1) { return false; }
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) { return false; }
	}
	return true;
}
#define bs bitset<50>
void per(int& ans) {
	ans %= p;
	if (ans < 0) { ans += p; }
}
#define upperbound(v,val) upper_bound(v.begin(),v.end(),val)-v.begin()
#define lowerbound(v,val) lower_bound(v.begin(),v.end(),val)-v.begin()
#define mat V<V<pin>>
int inf = 10000;
int linf = 10000;
pin p_mul(pin a, pin b) {
	pin c = mkp(max(b.first, a.first + b.second), a.second + b.second);
	return c;
}
mat m_mul(mat& a, mat& b) {
	int n = a.size();
	mat c(n, V<pin>(n, mkp(-inf, -inf)));
	int ze = 0;
	rep(i, n) {
		rep(j, n) {
			rep(k, n) {
				if (a[i][j].second > -linf && b[j][k].second > -linf) {
					pin x = p_mul(a[i][j], b[j][k]);
					mmax(c[i][k].first, x.first);
					mmax(c[i][k].second, x.second);
					mmax(c[i][k].first, ze);
				}
			}
		}
	}
	return c;
}
vvel disj_min(vel& v) {
	int n = v.size();
	vvel ret(22, vel(n));
	ret[0] = v;
	rep(i, 21) {
		rep(j, n) {
			int nex = j + (1 << i);
			if (nex < n) {
				ret[i + 1][j] = min(ret[i][j], ret[i][nex]);
			}
			else {
				ret[i + 1][j] = ret[i][j];
			}
		}
	}
	return ret;
}
vvel disj_max(vel& v) {
	int n = v.size();
	vvel ret(20, vel(n));
	ret[0] = v;
	rep(i, 19) {
		rep(j, n) {
			int nex = j + (1 << i);
			if (nex < n) {
				ret[i + 1][j] = max(ret[i][j], ret[i][nex]);
			}
			else {
				ret[i + 1][j] = ret[i][j];
			}
		}
	}
	return ret;
}
int find_min(vvel& dv, int l, int r) {
	int i = 19;
	while (l + (1 << i) > r) {
		i--;
	}
	return min(dv[i][l], dv[i][r - (1 << i)]);
}
int find_max(vvel& dv, int l, int r) {
	int i = 19;
	while (l + (1 << i) > r) {
		i--;
	}
	return max(dv[i][l], dv[i][r - (1 << i)]);
}
void pri(vel& v) {
	if (v.size() == 0) { return; }
	cout << v[0];
	rep(i, v.size() - 1) { cout << " " << v[i + 1]; }
	cout << endl;
	return;
}
int cm2(int n) {
	return (n * (n - 1)) / 2;
}
int cal(int st, V<V<pin>>& chi, vel& b, vel& sum) {
	int ans = 0;
	for (auto to : chi[st]) {
		ans += cal(to.first, chi, b, sum);
	}
	ans += b[st];
	ans %= 2;
	sum[st] = ans;
	return ans;
}
void solve(int st, V<V<pin>>& chi, vel& b, vel& sum, vel& ans) {
	for (auto to : chi[st]) {
		if (sum[to.first] == 1) {
			ans.push_back(to.second + 1);
			b[to.first] = 1 - b[to.first];
			b[st] = 1 - b[st];
		}
		solve(to.first, chi, b, sum, ans);
	}
}
vel lis_div(int n) {
	vel v;
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			int m = n / i;
			if (gcd(i, m) == 1) {
				v.push_back(i);
				v.push_back(m);
			}
		}
	}
	return v;
}
signed main() {
	int n, r; cin >> n >> r;
	cout << r + max((10 - n),(int)0) * 100 << endl;
	return 0;
}
