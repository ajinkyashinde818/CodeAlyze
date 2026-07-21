#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include <functional>
#include <map>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <list>
#include <numeric>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;
const double PI = 3.14159265358979323846;
const double EPS = 1e-12;
const ll INF = 1LL<<29;
const ll mod = 1e9+7;
#define rep(i,n) for(int (i)=0;(i)<(ll)(n);++(i))
#define repd(i,n,d) for(ll (i)=0;(i)<(ll)(n);(i)+=(d))
#define all(v) (v).begin(), (v).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset((m),(v),sizeof(m))
#define chmin(x,y) (x=min(x,y))
#define chmax(x,y) (x=max(x,y))
#define fst first
#define snd second
#define UNIQUE(x) (x).erase(unique(all(x)),(x).end())
template<class T> ostream &operator<<(ostream &os, const vector<T> &v){int n=v.size();rep(i,n)os<<v[i]<<(i==n-1?"":" ");return os;}

struct UF {
	vector<int> par, rank, sz;
	
	void init(int n){
		par = rank = vector<int>(n, 0);
		sz = vector<int>(n, 1);
		for(int i = 0; i < n; i++){
			par[i] = i;
		}
	}
	
	int find(int x){
		if(par[x] == x){
			return x;
		}else{
			return par[x] = find(par[x]);
		}
	}

	int size(int x){
		return sz[find(x)];
	}
	
	void unite(int x, int y){
		x = find(x);
		y = find(y);
		if(x == y) return;
		
		if(rank[x] < rank[y]){
			par[x] = y;
			sz[y] += sz[x];
		}else{
			par[y] = par[x];
			if(rank[x] == rank[y]) rank[y]++;
			sz[x] += sz[y];
		}
	}
	
	bool same(int x, int y){
		return find(x) == find(y);
	}
};

map<ll, ll> mk_comp(const vector<P> &x){
	map<ll, ll> dc;
	vector<ll> y; y.reserve(x.size()*2);
	for(auto p: x){
		y.pb(p.fst);
		y.pb(p.snd);
	}
	sort(all(y)); UNIQUE(y);
	rep(i, y.size()) dc[y[i]] = i;
	return dc;
}

int main(){
	int n;
	cin>>n;
	vector<ll> a[2];
	rep(i, 2) a[i] = vector<ll>(n+1, 0);
	rep(i, 2) rep(j, n) cin>>a[i][j];
	rep(i, 2) rep(j, n) a[i][n] ^= a[i][j];



	//auto dc = mk_comp(a[0]);
	//rep(i, 2) rep(j, n) a[i][j] = dc[a[i][j]];

	vector<P> v; v.reserve(n+1);
	rep(i, n+1) if(i==n||a[0][i]!=a[1][i]) v.pb(P(a[1][i], a[0][i]));
	auto dc = mk_comp(v);
	for(auto &p: v) p = P(dc[p.fst], dc[p.snd]);

	ll res = v.size();
	if(a[0][n]==a[1][n]) res--;
	else res--;
	//cerr<<res<<endl;
	rep(i, 2) sort(all(a[i]));
	if(a[0]!=a[1]){
		cout<<-1<<endl;
		return 0;
	}
	//for(auto x: v) cerr<<x.fst<<" "<<x.snd<<endl;
	//cerr<<"A"<<endl;
	UF uf;
	uf.init(dc.size());
	for(auto x: v) uf.unite(x.fst, x.snd);
	rep(i, dc.size()){
		if(uf.find(i)==i) res++;
		//cerr<<i<<" "<<uf.find(i)<<endl;
	}
	if(!v.empty()) res--;
	chmax(res, 0LL);
	cout<<res<<endl;

	return 0;
}
