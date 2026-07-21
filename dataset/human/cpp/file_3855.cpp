#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <numeric>
#include <cassert>
#include <cmath>
#include <map>
#include <set>

using namespace std;
typedef unsigned int uint;
typedef long long LL;
typedef pair<LL, LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int, int> PII;
typedef vector<PII > VPII;
typedef vector<VPII> VVPII;

#define FOR(k,a,b) for(int k(a); k < (b); ++k)
#define REP(k,a) for(int k=0; k < (a); ++k)
#define ABS(a) ((a)>0?(a):-(a))

long double calcDist(LL x, LL y, LL r, LL x2, LL y2, LL r2)
{
	LL d = (x - x2)*(x - x2) + (y - y2)*(y - y2);
	long double res = sqrt((long double) d);
	return max<long double>(res - r - r2,0);
}

int main(int argc, char** argv) {
#ifdef HOME
	freopen("in.txt", "rb", stdin);
	freopen("out.txt", "wb", stdout);
#endif
	int x1, x2, y1, y2, N;
	scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2,&N);
	vector<int> x(N+2), y(N+2), r(N+2);
	REP(i, N)
	{
		scanf("%d %d %d", &x[i], &y[i], &r[i]);
	}
	x[N] = x1, y[N] = y1, x[N + 1] = x2, y[N + 1] = y2;
	vector<vector<long double > > dist(N + 2,vector<long double>(N+2) );
	REP(i, N+2) REP(j,N+2)
	{
		dist[i][j] = calcDist(x[i], y[i], r[i], x[j], y[j], r[j]);
	}
	const long double INF = 1e11;
	vector<long double> d(N+2,INF);
	set<pair<long double, int > > Q;
	d[N] = 0;
	Q.insert(make_pair(0, N));
	while(!Q.empty())
	{
		long double actd = Q.begin()->first;
		int act = Q.begin()->second;
		Q.erase(Q.begin());
		REP(i, N + 2)
		{
			long double nd = actd + dist[act][i];
			if (d[i] > nd)
			{
				if (d[i] != INF)
				{
					Q.erase(make_pair(d[i], i));
				}
				d[i] = nd;
				Q.insert(make_pair(nd, i));
			}
			
		}
	}
	printf("%.11Lf\n", d[N + 1]);
	return 0;
}
