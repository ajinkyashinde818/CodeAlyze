#include <stdio.h>
#include <math.h>
#include <queue>
using namespace std;

int x[1020],y[1020],r[1020],N;
double d[1020]; bool chk[1020];

int main()
{
	scanf ("%d %d %d %d",x,y,x+1,y+1);
	scanf ("%d",&N); N+=2;
	for (int i=2;i<N;i++) scanf ("%d %d %d",&x[i],&y[i],&r[i]);
	for (int i=0;i<N;i++){
		d[i] = 1e18;
	}

	priority_queue<pair<double, int> > Q;
	Q.push({0,0}); d[0] = 0;
	while (!Q.empty()){
		int p = Q.top().second;
		double c = -Q.top().first; Q.pop();

		if (chk[p]) continue;
		chk[p] = 1;

		for (int q=0;q<N;q++) if (p != q){
			double dist = hypot(x[p]-x[q],y[p]-y[q]);
			dist -= r[p] + r[q];
			if (dist < 0) dist = 0;
			dist += c;
			if (d[q] > dist){
				Q.push({-dist,q}); d[q] = dist;
			}
		}
	}

	printf ("%.12lf\n",d[1]);

	return 0;
}
