#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <stack>
#include <numeric>
#include <bitset>
#include <math.h>
#include <iomanip>
#include <sstream>



typedef long long ll;
#define PI 3.14159265359
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define mp make_pair
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define decp(n) cout<<fixed<<setprecision((int)n)
#define _GLIBCXX_DEBAC
#include <functional>

/*map<Keyの型, Valueの型> 変数名;
queue<型> 変数名;
priority_queue<型> 変数名;
priority_queue<型, vector<型>, greater<型>> 変数名;*/
//copy(v1.begin(), v1.end(), back_inserter(v2));
using namespace std;

ll gcd(ll a, ll b) {
	if (b == 0)return a;
	return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
	ll c;
	c =  gcd(a, b);
	return a/c*b;
}

struct UnionFind {
	//自身が親であれば、その集合に属する頂点数に-1を掛けたもの
	//そうでなければ親のid
	vector<int> r;

	UnionFind(int n) {
		r = vector<int>(n, -1);
	}
	int root(int x) {
		if (r[x] < 0)return x;
		return r[x] = root(r[x]);
	}
	bool unite(int x, int y) {
		x = root(x);
		y = root(y);
		if (x == y)return false;
		if (r[x] > r[y])swap(x, y);
		r[x] += r[y];
		r[y] = x;
		return true;
	}
	bool same(int x, int y) {
		return root(x) == root(y);
	}
	int size(int x) {
		return -r[root(x)];
	}
};

int bubblesort(int a[], int n) {
	int sw = 0;
	bool flag = 1;
	for (int i = 0; flag; i++) {
		flag = 0;
		for (int j = n - 1; j >= i + 1; j--) {
			if (a[j] < a[j - 1]) {
				swap(a[j], a[j - 1]);
				flag = 1;
				sw += 1;
			}
		}
	}
	return sw;
}

int a_z()
{
	for (int i = 0; i <= ('Z' - 'A'); i++) {
		cout << (char)('A' + i);
	}
	return 0;
}

int selecttionsort(int a[], int n) {
	int t, sw = 0, minj;
	for (int i = 0; i < n - 1; i++) {
		minj = i;
		for (int j = 0; j < n - 1; j++) {
			if (a[j] < a[minj]) {
				minj = j;
			}
		}
		t = a[i]; a[i] = a[minj]; a[minj] = t;
		if (i != minj) sw += 1;

	}
	return sw;
}

bool is_prime(int x) {
	if (x <= 1) return false;
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) return false;
	}
	return true;
}

const ll mod = 1000000007;

map<string, int> memo;

using P = pair<ll, ll>;

/*void dfs(int v, int p = -1) {
	for (int u : to[v]) {
		if (u == p) continue;
		ans[u] += ans[v];
		dfs(u, v);
	}
}*/
ll findIndex(int value, vector<ll> a)
{

	for (ll i = 0; i < (ll)a.size(); i++) {
		if (a[i] == value) {
			return i;
		}
	}
	return -1;
}

struct mint {
	ll x;
	mint(ll x = 0) :x(x% mod) {}
	mint pow(ll t) const {
		if (!t)return 1;
		mint a = pow(t >> 1);
		a *= a;
		if (t & 1)a *= *this;
		return a;
	}
	mint inv() const {
		return pow(mod - 2);
	}
	mint& operator+=(const mint a) {
		if ((x += a.x) >= mod) x -= mod;
		return *this;
	}
	mint& operator-=(const mint a) {
		if ((x += mod - a.x) >= mod)x -= mod;
		return *this;
	}
	mint& operator *= (const mint a) {
		(x *= a.x) %= mod;
		return *this;
	}
	mint& operator/=(const mint a) {
		return (*this) *= a.inv();
	}
	mint operator+(const mint a) const {
		mint res(*this);
		return res += a;
	}
	mint operator-(const mint a)const {
		mint res(*this);
		return res -= a;
	}
	mint operator*(const mint a) {
		mint res(*this);
		return res *= a;
	}
	mint operator/(const mint a) {
		mint res(*this);
		return res /= a;
	}
};

struct combination {
	vector<mint> fact, ifact;
	combination(ll n) :fact(n + 1), ifact(n + 1) {

		fact[0] = 1;
		for (ll i = 1; i <= n; i++) fact[i] = fact[i - 1] * i;
		ifact[n] = fact[n].inv();
		for (ll i = n; i >= 1; i--) {
			ifact[i - 1] = ifact[i] * i;
		}
	}
	mint operator()(ll n, ll k) {
		if (k<0 || k>n)return 0;
		return fact[n] * ifact[k] * ifact[n - k];
	}
};

template<typename T>



struct BIT {
	int n;
	vector<T> d;
	BIT(int n = 0) :n(n), d(n + 1) {}
	void add(int i, T x = 1) {
		for (i++; i <= n; i += i & -i) {
			d[i] += x;
		}
	}

	T sum(int i) {
		T x = 0;
		for (i++; i; i -= i & -i) {
			x += d[i];
		}
		return x;
	}

	T sum(int l, int r) {
		return sum(r - 1) - sum(l - 1);
	}
};

const int INF = 1001001001;
const int M = 1000001;

string f(ll n) {
	if (n == 0)return "";
	n--;
	return f(n / 26) + string(1, 'a' + n % 26);
}

string x(ll n) {
	string s = "";
	if (n == 0)return "";
	n--;
	s += 'a' + n % 26;
	return x(n / 26) + s;
}

float round_n(float number, double n) {
	number = number * pow(10, n - 1);
	number = round(number);
	number /= pow(10, n - 1);
	return number;
}

ll kaizyou(ll n) {
	ll ans = 1;
	if (n == 0) return 0;
	for (ll i = 1; i <= n; i++) {
		ans *= i;
	}

	return ans;
}
ll ruiseki(ll n) {
	ll ans = 0;
	for (ll i = 0; i <= n; i++) {
		ans += i;
	}
	return ans;
}
ll nisin(ll n) {
	ll ans = 0;
	for (int i = 0; n > 0; i++) {
		ans = ans + (n % 2) * pow(10, i);
		n /= 2;
	}
	return ans;
}
ll yakusuu(ll x) {
	ll anss = 1;
	vector<ll>a(x + 1);
	ll num = x;
	for (ll i = 2; i <= x; i++) {
		while (num % i == 0) {
			a.at(i)++;
			num /= i;
		}
	}
	for (ll i = 2; i <= x; i++) {
		anss *= a[i] + 1;
	}
	return anss;
}

int deg[100005];
vector<int> to[100005];


int main() {
	int n;
	cin >> n;
	vector<ll>a(n);
	ll b = 0,c=0,ans=1e18;
	rep(i, n) {
		cin >> a[i];
		b += a[i];
	}

	rep(i, n) {
		c += a[i];
		if(i+1<n)ans = min(ans, abs(b - 2*c));
	}
	cout << ans << endl;
	return 0;
}
