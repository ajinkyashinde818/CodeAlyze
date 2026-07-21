#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <stdio.h>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#define rep(i,a,n) for(ll i =(a);i<(n);++i)
#define urep(i,a,n) for(ll i = (a);i>=(n);--i)
#define all(x) (x).begin(),(x).end()
#define INF 1e18
const int mod = 1e9 + 7;
typedef long long ll;
using namespace std;
ll dx[4] = { 1,-1,0,0 };
ll dy[4] = { 0,0,1,-1 };
ll N,M,X,Y,A,B,C,D,Q,K,R,W,H,P,L,G;
ll ans;
string S,T;
ll y[101010];
ll a[101010];
ll b[101010];
ll t[101010];
ll p[101010];
ll n[101010];
ll l[101010];
ll r[101010];
ll gcd(ll a, ll b) {
	if (b == 0)return a;
	else return gcd(b, a%b);
}
struct Edge{
	ll to,cost;
	 Edge(ll to, ll cost) : to(to), cost(cost) {}
};
typedef vector<vector<Edge> > AdjList;
AdjList graph;
vector<ll> dist;

struct UnionFind {
    vector<ll> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
	vector<ll> size;
    UnionFind(ll N) : par(N),size(N) { //最初は全てが根であるとして初期化
        for(ll i = 0; i < N; i++) par[i] = i;
		for(ll i = 0; i < N; i++) size[i] = 1;
    }

    ll root(ll x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }
	ll GetSize(ll x){
		return size[root(x)];
	}

    void unite(ll x, ll y) { // xとyの木を併合
        ll rx = root(x); //xの根をrx
        ll ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
		size[ry]+=size[rx];

    }

    bool same(ll x, ll y) { // 2つのデータx, yが属する木が同じならtrueを返す
        ll rx = root(x);
        ll ry = root(y);
        return rx == ry;
    }
};
ll sr,sc;
int main() {
    cin>>R>>G>>B>>N;
    rep(i,0,N+1)rep(j,0,N+1){
        if(N-R*i-G*j>=0){
            if((N-R*i-G*j)%B==0)ans++;
        }
        
    }
    cout<<ans<<endl;;
	return 0;
}
