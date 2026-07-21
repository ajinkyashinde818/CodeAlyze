#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<bool> vb;
const ll oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-12;
#define sz(c) ll((c).size())
#define all(c) begin(c), end(c)
#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define FORD(i,a,b) for (ll i = (b)-1; i >= (a); i--)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define has(c,i) ((c).find(i) != end(c))
#define DBGDO(X) ({ if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll xs, ys, xt, yt, n;
	cin >> xs >> ys >> xt >> yt >> n;

	n += 2;
	vl x(n), y(n), r(n);
	x[0] = xs, y[0] = ys, r[0] = 0;
	x[1] = xt, y[1] = yt, r[1] = 0;

	FOR(i,2,n) cin >> x[i] >> y[i] >> r[i];

	vector<long double> dist(n,1e100);
	vector<bool> done(n);

	dist[0] = 0;
	
	while (true) {
		ll i = -1;
		FOR(j,0,n) if (!done[j] && (i == -1 || dist[j] < dist[i])) i = j;
		done[i] = true;
		if (i == 1) break;
		FOR(j,0,n) if (j != i) {
			ll dx = x[i]-x[j], dy = y[i]-y[j];
			long double len = 0;
			if (dx*dx + dy*dy > (r[i]+r[j])*(r[i]+r[j]))
				len = sqrt((long double)(dx*dx + dy*dy)) - r[i] - r[j];
			
			if (dist[j] < dist[i] + len) continue;
			dist[j] = dist[i] + len;
		}
	}
	cout << fixed << setprecision(40) << dist[1] << endl;
}
