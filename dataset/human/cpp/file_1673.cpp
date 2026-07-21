#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i = 0; i < (n); i++)
#define repr(i,b,e) for(int i = (b); i <= (e); i++)

#define pr(x) do{cerr << (#x) << " = " << (x) << endl;}while(0)
#define pri(x,i) do{cerr << (#x) << "[" << i << "] = " << (x[i]) << endl;}while(0)

namespace std {
	template<class S, class T> pair<S, T> operator + (const pair<S, T> &a, const pair<S, T> &b) {return mp<S, T>(a.first + b.first, a.second + b.second);}
	template<class S, class T> pair<S, T> operator - (const pair<S, T> &a, const pair<S, T> &b) {return mp<S, T>(a.first - b.first, a.second - b.second);}
	template<class S, class T> pair<S, T>& operator += (pair<S, T> &a, const pair<S, T> &other) {return a = a + other;}
	template<class S, class T> pair<S, T>& operator -= (pair<S, T> &a, const pair<S, T> &other) {return a = a - other;}
	template<class S, class T> ostream& operator << (ostream& ost, pair<S, T> p) {ost << "(" << p.first << ", " << p.second << ")";return ost;}
	template<class T> ostream& print_iterable_container(ostream& ost, T& container) {
		for (auto&& iter = begin(container); iter != end(container); ++iter) ost << (iter == begin(container) ? " [ " : ", ") << (*iter);
		return ost << " ]";
	}
#	define APPLY_PRINT_ITERABLE_CONTAINER(container_type)\
	template<class T> ostream& operator << (ostream& ost, container_type<T>& container) {\
		return print_iterable_container(ost, container);\
	}
	APPLY_PRINT_ITERABLE_CONTAINER(vector);
	APPLY_PRINT_ITERABLE_CONTAINER(list);
	APPLY_PRINT_ITERABLE_CONTAINER(deque);
}

template<class T> inline bool CHMAX(T &l,const T &r){return l<r?l=r,1:0;}
template<class T> inline bool CHMIN(T &l,const T &r){return l>r?l=r,1:0;}

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vpii = vector<pii>;
using vpll = vector<pll>;

using ld = long double;

template<class T> using VV = vector<vector<T> >;
template<class T> using maxPQ = priority_queue<T>;
template<class T> using minPQ = priority_queue<T, vector<T>, greater<T> >;
template<class T, class U> using uomap = unordered_map<T, U>;
template<class T> using uoset = unordered_set<T>;

const ll INF = 1001001001;
const ll INFll = (ll)INF * INF;
const ll MOD = 1000000007;
const ll MOD_FFT = 998244353;
const ld EPS = 1e-15;

//function<void(int,int)> tensi_no_3p=[&](int v,int d){
//};

int main() {
	int N; cin >> N;
	int K = 0;
	rep(i, 10000) if (i * (i - 1) / 2 == N) {K = i; break;}
	if (K == 0) {
		cout << "No" << endl;
		return 0;
	}
	vpii C;
	rep(i, K) repr(k, i + 1 , K - 1) C.pb(mp(i,k));
	vvi groups(K);
	rep(i, N) {
		int a = C[i].first;
		int b = C[i].second;
		groups[a].pb(i);
		groups[b].pb(i);
	}
	cout << "Yes" << endl;
	cout << K << endl;
	rep(k, K) {
		cout << groups[k].size();
		for (auto i : groups[k]) {
			cout << " " << (i + 1);
		}
		cout << endl;
	}
	return 0;
}
