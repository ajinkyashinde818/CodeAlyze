#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <stack>
#include <queue>
#include <bitset>
#include <numeric>
#include <cassert>
#ifdef DEBUG
#include "./Lib/debug.hpp"
#else
#define dump(...)
template<class T>inline auto d_val(T a, T b) { return a; }
#endif

/* (=＾o＾=) */
#define int ll

/* macro */
#define FOR(i, b, e) for(ll i = (ll)(b); i < (ll)(e); ++i)
#define RFOR(i, b, e) for(ll i = (ll)(e-1); i >= (ll)(b); --i)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) RFOR(i, 0, n)
#define REPC(x,c) for(const auto& x:(c))
#define REPI2(it,b,e) for(auto it = (b); it != (e); ++it)
#define REPI(it,c) REPI2(it, (c).begin(), (c).end())
#define RREPI(it,c) REPI2(it, (c).rbegin(), (c).rend())
#define REPI_ERACE2(it, b, e) for(auto it = (b); it != (e);)
#define REPI_ERACE(it, c) REPI_ERACE2(it, (c).begin(), (c).end())
#define ALL(x) (x).begin(),(x).end()
#define cauto const auto&
/* macro func */
#define SORT(x) do{sort(ALL(x));}while(false)
#define RSORT(x) do{sort((x).rbegin(),(x).rend());}while(false)
#define UNIQUE(v) do{v.erase( unique(v.begin(), v.end()), v.end() );}while(false)
#define MAX(x,y) do{x = std::max(x,y);}while(false)
#define MIN(x,y) do{x = std::min(x,y);}while(false)
#define BR do{cout<<"\n";}while(false)

/* type define */
using ll = long long;
using PAIR = std::pair<ll, ll>;
using VS = std::vector<std::string>;
using VL = std::vector<long long>;
using VVL = std::vector<VL>;
using VVVL = std::vector<VVL>;
using VD = std::vector<double>;
template<class T>
using V = std::vector<T>;

/* using std */
using std::cout;
constexpr char endl = '\n';
using std::cin;
using std::sort;
using std::pair;
using std::string;
using std::stack;
using std::queue;
using std::vector;
using std::list;
using std::map;
using std::unordered_map;
using std::multimap;
using std::unordered_multimap;
using std::set;
using std::unordered_set;
using std::unordered_multiset;
using std::multiset;
using std::bitset;
using std::priority_queue;

/* constant value */
constexpr ll MOD = 1000000007;
//constexpr ll MOD = 998244353;

/* Initial processing  */
struct Preprocessing { Preprocessing() { std::cin.tie(0); std::ios::sync_with_stdio(0); }; }_Preprocessing;

/* Remove the source of the bug */
signed pow(signed, signed) { assert(false); return -1; }

/* define hash */
namespace std { template <>	class hash<std::pair<ll, ll>> { public:	size_t operator()(const std::pair<ll, ll>& x) const { return hash<ll>()(1000000000 * x.first + x.second); } }; }

/* input */
template<class T> std::istream& operator >> (std::istream& is, vector<T>& vec) { for (T& x : vec) is >> x; return is; }

//=============================================================================================

/**
 *  累積和を生成
 *  閉区間([l,r])における値を取得
 */
class CumulativeSum {
	const ll size;
	std::vector<ll> sumList;
public:

	CumulativeSum() = delete;
	CumulativeSum(const std::vector<ll>& v) :size(v.size()), sumList(size + 1) {
		for (ll i = 0; i < size; ++i) {
			sumList[i + 1] = sumList[i] + v[i];
		}
	}
	ll get(ll n) {
		return sumList[n + 1];
	}
	ll get(ll l, ll r) {
		if (r < l) { return 0LL; }
		l = std::max(l, 0LL); r = std::min(r, size - 1);
		return sumList[r + 1] - sumList[l];
	}
};


signed main() {
	ll n, c;
	cin >> n >> c;
	VL x; x.reserve(n);
	VL v; v.reserve(n);
	REP(i, n) {
		ll a, b;
		cin >> a >> b;
		x.emplace_back(a);
		v.emplace_back(b);
	}

	auto sum = CumulativeSum(v);

	ll ans = 0LL;
	VL l; l.reserve(n);
	FOR(i, 0, n) { l.emplace_back(sum.get(i) - x[i]); }

	VL lMax; lMax.reserve(n);
	lMax.emplace_back(l[0]);
	FOR(i, 1, n) { lMax.emplace_back(std::max(*lMax.rbegin(), l[i])); }

	VL r; r.reserve(n);
	FOR(i, 0, n) { r.emplace_back(sum.get(i, n) - (c - x[i])); }

	VL rMax = r;
	RREP(i, n - 1) { MAX(rMax[i], rMax[i + 1]); }

	dump(lMax, rMax);

	MAX(ans, std::max(*lMax.rbegin(), *rMax.begin()));
	REP(i, n) {
		MAX(ans, lMax[i] - x[i] + ((i + 1 < n) ? rMax[i + 1] : 0LL));
		MAX(ans, rMax[i] - (c - x[i]) + ((i - 1 >= 0) ? lMax[i - 1] : 0LL));
	}

	cout << ans << endl;
}
