#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;
using ll = long long;
using DBL = double;
using VI = vector<int>;
using VD = vector<DBL>;
using VVI = vector<VI>;
using VVD = vector<VD>;
#define FOR(i,a,b) for(int i = a; i < b; i++)
#define REP(i,n) FOR(i,0,n)
#define SZ(a) ((int)((a).size()))
#define ALL(x) (x).begin(), (x).end()
#define SET(a,v) memset((a), (v), sizeof(a))
#define EB emplace_back
#define PB push_back
#define MP make_pair
#define ST first
#define ND second

#define trace(...) {__f(#__VA_ARGS__, __VA_ARGS__);}
template<typename Arg> void __f(const char* name, Arg&& arg) {
  cerr << name << " = " << arg << std::endl;
} template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " = " << arg1<<" | ";__f(comma+1, args...); }
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds; // OST: find_by_order, order_of_key
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// #pragma GCC optimize("Ofast")
// optimize("unroll-loops")
// target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// /*** RNGS ***/
// SEED=chrono::steady_clock::now().time_since_epoch().count();
// // or high_resolution_clock
// mt19937 rng(SEED); /*or*/ random_device rd; mt19937 rng(rd());
// uniform_int_distribution<> dis(MIN, MAX);// usage: dis(rng)
// struct chash {int operator()(int x) const {return x^SEED;}};
// gp_hash_table<int,int,chash>m;//use cc if very less updates
// /*** FAST IO ***/
// inline int scan(){ bool y=0; int x=0; char c=getchar_unlocked();
// while(c<'0'||c>'9'){ if(c=='-')y=1; c=getchar_unlocked();}
// while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+c-'0';c=getchar_unlocked();}
// return y?-x:x; }

const int N = 100010;
int idx = 1;
map<char, int> m[N];

void insert_string(const string &s) {
	int node = 0;
	for(auto&z: s) {
		if(m[node].count(z) == 0) m[node][z] = idx++;
		node = m[node][z];
	}
}

long long calc(int node, long long h) {
	if(SZ(m[node]) == 0) return 0;
	if(SZ(m[node]) == 1) {
		assert(h != 0);
		long long temp = 1;
		while(true) {
			if(temp * 2 <= h and h % (temp * 2) == 0) temp *= 2;
			else break;
		}
		// trace(temp, node, h);
		return (temp ^ (calc(m[node].begin()->second, h-1)));
	}
	if(SZ(m[node]) == 2) return ( (calc(m[node]['0'], h-1)) ^ (calc(m[node]['1'], h-1)) );
	assert(SZ(m[node]) <= 2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	long long l;
	cin >> n >> l;
	for(int i=1; i<=n; ++i) {
		string s;
		cin >> s;
		insert_string(s);
	}
	if(calc(0, l)) cout << "Alice\n";
	else cout << "Bob\n";
	return 0;
}
