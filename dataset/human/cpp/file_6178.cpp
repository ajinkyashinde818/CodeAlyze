#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <functional>
#include <map>
#include <set>
#include <sys/timeb.h>
#include <fstream>
#include <random>
#include <regex>
#include <chrono>
#include <bitset>
#include <cassert>
#include <iomanip>
#include <limits>

using namespace std;

//#define DEBUG_

#define repr(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repr(i,0,n)
#define reprrev(i,a,b) for(int i=(int)(b)-1;i>=(int)(a);i--)
#define reprev(i,n) reprrev(i,0,n)
#define repi(itr,ds) for(auto itr=ds.begin();itr!=ds.end();itr++)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define mp make_pair
#define mt make_tuple
#define INF 1050000000
#define INFR INT_MAX
#define INFL (long long)(4e18)
#define INFLR LLONG_MAX
#define EPS (1e-10)
#define MOD 1000000007
#define PI 3.141592653589793238
#define RMAX 4294967295


#ifdef DEBUG_
#define DEB
#else
#define DEB if(false)
#endif

#ifdef DEBUG_
#define dump(...) DUMPOUT<<"  "; \
dump_func(string(#__VA_ARGS__) + ":", "[" + to_string(__LINE__) + ":" + __FUNCTION__ + "]"); \
DUMPOUT<<"    "; \
dump_func(__VA_ARGS__)
#else
#define dump(...)
#endif

typedef long long ll;
typedef pair<int, int> Pi;
typedef pair<ll, ll> Pll;
typedef pair<double, double> Pd;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<Pi> vPi;
typedef vector<Pll> vPll;
typedef vector<Pd>vPd;
typedef vector<vector<int> > vvi;
typedef vector<vector<bool> > vvb;
typedef vector<vector<ll> > vvll;
typedef vector<vector<char> > vvc;
typedef vector<vector<string> > vvs;
typedef vector<vector<double> > vvd;
typedef vector<vector<Pi> > vvPi;
typedef vector<vector<vector<int> > > vvvi;
typedef vector<vector<vector<ll> > > vvvll;
typedef priority_queue<int, vector<int>, greater<int> > pqli;
typedef priority_queue<ll, vector<ll>, greater<ll> > pqlll;
typedef priority_queue<Pi, vector<Pi>, greater<Pi> > pqlP;
template <class T>
using vec = vector<T>;
template<class T>
using pql = priority_queue<T, vector<T>, greater<T>>;
string debug_show(Pi a) {
	return "(" + to_string(a.first) + "," + to_string(a.second) + ")";
}

#define DUMPOUT cerr

void dump_func() {
	DUMPOUT << endl;
}
template <class Head, class... Tail>
void dump_func(Head&& head, Tail&&... tail) {
	DUMPOUT << head;
	if (sizeof...(Tail) <= 1) {
		DUMPOUT << " ";
	}
	else {
		DUMPOUT << ", ";
	}
	dump_func(std::move(tail)...);
}

// vector
template<typename T>
istream& operator >> (istream& is, vector<T>& vec) {
	for (T& x : vec) is >> x;
	return is;
}
// pair
template<typename T, typename U>
ostream& operator << (ostream& os, pair<T, U>& pair_var) {
	os << "(" << pair_var.first << "," << pair_var.second << ")";
	return os;
}
// pair
template<typename T, typename U>
ostream& operator << (ostream& os, const pair<T, U>& pair_var) {
	os << "(" << pair_var.first << "," << pair_var.second << ")";
	return os;
}
// vector
template<typename T>
ostream& operator << (ostream& os, const vector<T>& vec) {
	os << "{";
	for (int i = 0; i < vec.size(); i++) {
		os << vec[i] << (i + 1 == vec.size() ? "" : ", ");
	}
	os << "}";
	return os;
}
// map
template<typename T, typename U>
ostream& operator << (ostream& os, map<T, U>& map_var) {
	os << "{";
	repi(itr, map_var) {
		os << "(" << itr->first << "," << itr->second << ")";
		itr++;
		if (itr == map_var.end()) os << ", ";
		itr--;
	}
	os << "}";
	return os;
}
// set
template<typename T>
ostream& operator << (ostream& os, set<T>& set_var) {
	os << "{";
	repi(itr, set_var) {
		os << "  " << *itr << endl;
		itr++;
		if (itr == set_var.end()) os << ", ";
		itr--;
	}
	os << "}";
	return os;
}
string YN(bool y, int id = 0) { if (id)cout << id; return (y ? "YES" : "NO"); }
string yn(bool y, int id = 0) { if (id)cout << id; return (y ? "Yes" : "No"); }
string ON(bool y, int id = 0) { if (id)cout << id; return (y ? "OK" : "NG"); }

int dir4[4][2] = { { 0,-1 },{ -1,0 },{ 1,0 },{ 0,1 } };
int dir8[8][2] = { { -1,-1 },{ 0,-1 },{ 1,-1 },{ -1,0 },{ 1,0 },{ -1,1 },{ 0,1 },{ 1,1 } };

// [a,b)
int irand(int a, int b) {
	static mt19937 Rand(static_cast<unsigned int>(time(nullptr)));
	uniform_int_distribution<int> dist(a, b - 1);
	return dist(Rand);
}

// [a,b)
double drand(int a, int b) {
	static mt19937 Rand(static_cast<unsigned int>(time(nullptr)));
	uniform_real_distribution<double> dist(a, b);
	return dist(Rand);
}
struct Edge {
	int from, to, cost;
};
using Graph = vec<vec<Edge>>;

//======================================================

class SegTree {
public:
	int n, height;
	vector<ll> dat;

	ll def = -INFL;
	ll operation(ll a, ll b) {
		return max(a, b);
	}

	// 初期化（_nは必要な要素数）
	SegTree(int _n) {
		n = 1;
		height = 1;
		while (n < _n) {
			n *= 2;
			height++;
		}
		dat = vector<ll>(2 * n - 1, def);
	}

	// 場所i(0-indexed)にxを足す
	void add(int i, ll x) {
		i += n - 1;
		dat[i] += x;
		while (i > 0) {
			i = (i - 1) / 2;
			dat[i] += x;
		}
	}

	// 場所i(0-indexed)の値をxに更新
	void change(int i, ll x) {
		i += n - 1;
		dat[i] = x;
		while (i > 0) {
			i = (i - 1) / 2;
			dat[i] = operation(dat[i * 2 + 1], dat[i * 2 + 2]);
		}
	}

	ll at(int i) {
		return dat[i + n - 1];
	}

	// 区間[a,b)の総和。ノードk=[l,r)に着目している。
	ll _query(int a, int b, int k, int l, int r) {
		if (r <= a || b <= l)return def;  // 交差しない
		if (a <= l && r <= b)return dat[k];   // a,l,r,bの順で完全に含まれる
		else {
			ll c1 = _query(a, b, 2 * k + 1, l, (l + r) / 2);    // 左の子
			ll c2 = _query(a, b, 2 * k + 2, (l + r) / 2, r);    // 右の子
			return operation(c1, c2);
		}
	}

	// 内部クエリ_query()を呼び出す
	ll query(int a, int b) {
		return _query(a, b, 0, 0, n);
	}
};


int main() {
	int N;
	ll C;
	cin >> N >> C;

	vll x(N), v(N);

	rep(i, N) {
		cin >> x[i] >> v[i];
	}

	ll ans = 0;

	SegTree cw(N), ccw(N);

	ll val = 0;

	rep(i, N) {
		val += v[i] - (i == 0 ? x[0] : x[i] - x[i - 1]);
		cw.change(i, val);
		ans = max(ans, val);
	}

	val = 0;
	reprev(i, N) {
		val += v[i] - (i == N - 1 ? C - x[N - 1] : x[i + 1] - x[i]);
		ccw.change(i, val);
		ans = max(ans, val);
	}

	rep(i, N) {
		ll val2 = cw.at(i) - x[i] + ccw.query(i + 1, N);
		dump(i, cw.at(i), ccw.query(i + 1, N), val2);
		ans = max(ans, val2);
	}

	rep(i, N) {
		ll val2 = ccw.at(i) - (C - x[i]) + cw.query(0, i);
		dump(i, val2);
		ans = max(ans, val2);
	}

	cout << ans << endl;

	return 0;
}
