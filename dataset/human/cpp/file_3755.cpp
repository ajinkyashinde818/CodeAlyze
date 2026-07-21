#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using ll = long long;
using pll = pair<ll,ll>;
using pli = pair<ll,int>;
using pil = pair<int,ll>;
using ld = long double;
using ui = unsigned int;
using ull = unsigned long long;
using ui128 = __uint128_t;
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define lc ind<<1
#define rc ind<<1|1
const int MN = 1e5 + 2, LOG = 17, INF = 1e8;
struct Circle {
	int x,y,r;
	ld dist (const Circle &o) {
		return max((ld)0,sqrtl((ll)(x-o.x)*(x-o.x) + (ll)(y-o.y)*(y-o.y)) - r - o.r);
	} 
};
int main () { 
	int sx,sy,ex,ey,n;
	scanf ("%d %d %d %d %d",&sx,&sy,&ex,&ey,&n);
	vector<Circle> circles(n+2); vector<ld> dist(n+2);
	for (int i = 1; i <= n; i++) scanf ("%d %d %d",&circles[i].x,&circles[i].y,&circles[i].r);
	circles[0] = {sx,sy,0}; circles[n+1] = {ex,ey,0};
	for (int i = 1; i <= n+1; i++) dist[i] = 1e18;
	dist[0] = 0;
	vector<bool> done(n+2);
	for (int iter = 1; iter <= n+2; iter++) {
		int mn = -1;
		for (int i = 0; i <= n+1; i++) if (!done[i] && (mn == -1 || dist[i] < dist[mn])) mn = i;
		done[mn] = 1;
		for (int i = 0; i <= n+1; i++) if (!done[i] && dist[mn] + circles[mn].dist(circles[i]) < dist[i]) {
			dist[i] = dist[mn] + circles[mn].dist(circles[i]);
		}
	}
	printf ("%.10Lf\n",dist[n+1]);
    return 0;
}
