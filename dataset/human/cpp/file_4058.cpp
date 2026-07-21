#include<iostream>
#include<cstdio>
#include<cstring>
#include <cstdlib>  
#include <math.h>
#include <cmath>
#include<cctype>
#include<string>
#include<set>
#include<iomanip>
#include <map>
#include<algorithm>
#include <functional>
#include<vector>
#include<climits>
#include<stack>
#include<queue>
#include<bitset>
#include <deque>
#include <climits>
#include <typeinfo>
#include <utility> 
using namespace std;
using ll = long long;
template<typename T>using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
const ll inf = 1LL << 60;
#define all(x) (x).begin(),(x).end()
#define puts(x) cout << x << endl;
#define rep(i,m,n) for(ll i = m;i < n;++i)
#define pb push_back
#define fore(i,a) for(auto &i:a)
#define rrep(i,m,n) for(ll i = m;i >= n;--i)
#define INF INT_MAX/2

double dist[1010];
int vis[1010];
int main() {
	ll xs, ys, xt, yt, N;
	cin >> xs >> ys >> xt >> yt >> N;

	vector<vector<ll>>v;
	vector<vector<double>>e(1010,vector<double>(1010,0));
	v.pb({xs,ys,0});
	rep(i, 0, N) {
		ll x, y, r;
		cin >> x >> y >> r;
		v.pb({ x,y,r });
	}
	v.pb({xt,yt,0});

	rep(i, 0, N+2) {
		rep(j, 0, N+2) {
			if (i == j)continue;
			ll x1 = v[i][0];
			ll y1 = v[i][1];
			double R1 = v[i][2];
			ll x2 = v[j][0];
			ll y2 = v[j][1];
			double R2 = v[j][2];
			ll tmp = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
			double dist = sqrt(tmp);
			double cost = (dist - R1 - R2 > 0) ? dist - R1 - R2 : 0;
			e[i][j] = cost;
		}
	}

	rep(i, 0, 1010)dist[i] = (double)inf;
	min_priority_queue<pair<double,ll>>q;
	dist[0] = 0.0;
	q.push({0.0,0});
	while (q.size()) {
		auto p = q.top();
		q.pop();
		ll now = p.second;
		double d = p.first;
		if (vis[now])continue;
		vis[now] = 1;
		rep(j, 0, N + 2) {
			if (now == j)continue;
			double cc = d + e[now][j];
			if (cc < dist[j]) {
				dist[j] = cc;
				q.push({cc,j});
			}
		}
	}

	printf("%.25f",dist[N+1]);
	puts("")

	return 0;
}
