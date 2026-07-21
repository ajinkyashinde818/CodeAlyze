#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<math.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int, int>;
using pll = pair<ll, ll>;
#define MOD 1000000007LL
#define INF 1000000000LL
#define EPS 1e-10
#define FOR(i,n,m) for(ll i=n;i<(int)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v)  sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll xs, ys, xt, yt;
	cin >> xs >> ys >> xt >> yt;
	int n;
	cin >> n;
	vector<pair<pll, ll>> b(n + 2);
	b[0] = {pll(xs, ys), 0};
	b[n + 1] = {pll(xt, yt), 0};
	REP(i, n) {
		ll x, y, r;
		cin >> x >> y >> r;
		b[i + 1] = {pll(x, y), r};
	}
	n += 2;
	vector<vector<ld>> g(n, vector<ld>(n, 0));
	REP(i, n) FOR(j, i + 1, n) {
		g[i][j] = g[j][i] = max((ld)0,
					  (ld)sqrt(pow((b[i].first.first - b[j].first.first), 2)
						  +pow((b[i].first.second - b[j].first.second), 2))
					  - b[i].second - b[j].second);
	}
	vector<ld> dir(n, INF * INF + 10);
	priority_queue<pair<int, ld>, vector<pair<int, ld>>, greater<pair<int, ld>>> Q;
	Q.push({0, 0});
	while(!Q.empty()) {
		int p = Q.top().first;
		ld d = Q.top().second;
		Q.pop();
		REP(i, n) {
			if(i == p) continue;
			if(dir[i] > d + g[p][i]) {
				dir[i] = d + g[p][i];
				Q.push({i, dir[i]});
			}
		}
	}
	cout << fixed << setprecision(39) << dir[n - 1] << endl;
	return 0;
}
/* --------------------------------------- */
