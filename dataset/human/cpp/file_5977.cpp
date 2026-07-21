#include <iostream>
#include <queue>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <stack>
#include <limits>
#include <climits>
#include <cassert>
#include <fstream>
#include <cstring>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <ciso646>
#include <set>
#include <array>
#include <unordered_map>

using namespace std;

#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)

#define inf 0x3f3f3f3f
#define PB push_back
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define SET(a,c) memset(a,c,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define VS vector<string>
#define VI vector<ll>
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define MIN(a,b) (a>b?b:a)
#define MAX(a,b) (a>b?a:b)
#define pi 2*acos(0.0)
#define INFILE() freopen("in0.txt","r",stdin)
#define OUTFILE()freopen("out0.txt","w",stdout)
#define ll long long
#define ull unsigned long long
#define pii pair<ll,ll>
#define pcc pair<char,char>
#define pic pair<ll,char>
#define pci pair<char,ll>
#define eps 1e-14
#define FST first
#define SEC second
#define SETUP cin.tie(0), ios::sync_with_stdio(false), cout << setprecision(15)

namespace {
	struct input_returnner {
		ll N; input_returnner(ll N_ = 0) :N(N_) {}
		template<typename T> operator vector<T>() const { vector<T> res(N); for (auto &a : res) cin >> a; return std::move(res); }
		template<typename T> operator T() const { T res; cin >> res; return res; }
		template<typename T> T operator - (T right) { return T(input_returnner()) - right; }
		template<typename T> T operator + (T right) { return T(input_returnner()) + right; }
		template<typename T> T operator * (T right) { return T(input_returnner()) * right; }
		template<typename T> T operator / (T right) { return T(input_returnner()) / right; }
		template<typename T> T operator << (T right) { return T(input_returnner()) << right; }
		template<typename T> T operator >> (T right) { return T(input_returnner()) >> right; }
	};
	template<typename T> input_returnner in() { return in<T>(); }
	input_returnner in() { return input_returnner(); }
	input_returnner in(ll N) { return std::move(input_returnner(N)); }
}

const ll MOD = 1e9 + 7;

void solve();

signed main() {
	SETUP;
	solve();
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}

#define int ll

template<class T>
class segtree {
private:
	int n;
	vector<T> dat;

	T query(int a, int b, int k, int l, int r) {
		if (r <= a || b <= l) return numeric_limits<T>::max();

		if (a <= l & r <= b) return dat[k];
		else {
			T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return min(vl, vr);
		}
	}
public:
	segtree(int n_) {
		n = 1;
		while (n < n_) n *= 2;
		dat.resize(2 * n - 1);
		for (int i = 0; i < 2 * n - 1; ++i) dat[i] = numeric_limits<T>::max();
	}

	//kの値をaに変更
	void update(int k, int a) {
		k += n - 1;
		dat[k] = a;
		while (k > 0) {
			k = (k - 1) / 2;
			dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
		}
	}


	int query(int a, int b) {
		return query(a, b, 0, 0, n);
	}
};

void solve() {
	int N, C; cin >> N >> C;
	vector<pii> X;
	vector<pii> IX;
	REP(i, N) {
		int x, v; cin >> x >> v;
		X.emplace_back(x, v);
		IX.emplace_back(C - x, v);
	}
	if (N == 1) {
		int res = max(X[0].second - X[0].first, IX[0].second - IX[0].first);
		cout << max(0LL, res) << endl;
		return;
	}
	sort(ALL(X));
	sort(ALL(IX));
	vector<int> sumIX(N);
	vector<int> sumX(N);
	int dis = 0;
	sumIX[0] = IX[0].second - IX[0].first;
	vector<int> imaxs(N);
	vector<int> maxs(N);
	pii ma;
	int res = 0;
	sumIX[0] = IX[0].second - IX[0].first;
	imaxs[0] = sumIX[0];
	FOR(i,1,N){
		sumIX[i] = sumIX[i-1] + IX[i].second - (IX[i].first - IX[i-1].first);
		imaxs[i] = max(sumIX[i], imaxs[i - 1]);
		res = max(res, sumIX[i]);
	}
	reverse(ALL(sumIX));
	reverse(ALL(imaxs));
	reverse(ALL(IX));

	sumX[0] = X[0].second - X[0].first;
	maxs[0] = sumX[0];
	FOR(i,1,N){
		sumX[i] = sumX[i-1] + X[i].second - (X[i].first - X[i-1].first);
		maxs[i] = max(sumX[i], maxs[i - 1]);
		res = max(res, sumX[i]);
	}

	REP(i, N-1) {
		int val = sumX[i] - X[i].first + imaxs[i+1]; 
		if (res < val) res = val;
	}
	FOR(i, 1, N) {
		int val = sumIX[i] - IX[i].first + maxs[i - 1];
		if (res < val) res = val;
	}
	cout << res << endl;
}
