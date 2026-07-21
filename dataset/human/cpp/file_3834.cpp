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
typedef pair<double,ll> P;
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
#define chmin(X,Y) ((X)>(Y)?X=(Y),true:false)
#define chmax(X,Y) ((X)<(Y)?X=(Y),true:false)
#define fst first
#define snd second
#define UNIQUE(x) (x).erase(unique(all(x)),(x).end())
template<class T> ostream &operator<<(ostream &os, const vector<T> &v){int n=v.size();rep(i,n)os<<v[i]<<(i==n-1?"":" ");return os;}

#define N 1010
ll x[N], y[N], r[N], n;
double dist[N];

int main(){
	cin>>x[0]>>y[0]>>x[1]>>y[1]>>n;
	x[n+1] = x[1];
	y[n+1] = y[1];
	rep(i, n) cin>>x[i+1]>>y[i+1]>>r[i+1];
	fill(dist, dist+N, 1e100);
	priority_queue<P, vector<P>, greater<P> > q;
	q.push(P(0, 0));
	while(!q.empty()){
		P p = q.top(); q.pop();
		if(p.fst>dist[p.snd]) continue;
		rep(i, n+2){
			ll dx = x[i]-x[p.snd], dy = y[i]-y[p.snd], rr = r[i]+r[p.snd];
			double d = max(0.0, sqrt(dx*dx+dy*dy)-rr);
			if(p.fst+d+EPS<dist[i]){
				dist[i] = p.fst+d;
				q.push(P(dist[i], i));
			}
		}
	}
	cout.precision(9);
	cout<<fixed<<dist[n+1]<<endl;
	return 0;
}
