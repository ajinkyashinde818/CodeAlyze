#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
const double eps = 1e-9;

int n, sx, sy, ex, ey, x[N], y[N], r[N];
double c[N][N], dist[N], ans;

priority_queue<pair<double,int> > pq;

double d (int X1, int Y1, int X2, int Y2, int R) {
	return max(0.0, hypot(X1-X2, Y1-Y2)-R);
}

int main()
{
	scanf("%d%d%d%d%d",&sx,&sy,&ex,&ey,&n);
	for(int i=1;i<=n;i++) {
		scanf("%d%d%d",&x[i],&y[i],&r[i]);
		for(int j=1;j<i;j++) {
			c[i][j] = d(x[i], y[i], x[j], y[j], r[i]+r[j]);
			c[j][i] = c[i][j];
		}
		dist[i] = d(x[i], y[i], sx, sy, r[i]);
		pq.push({-dist[i], i});
	}
	while(!pq.empty()) {
		double V; int I; tie(V, I) = pq.top(); V *= -1; pq.pop();
		if(dist[I]+eps < V) continue;
		for(int i=1;i<=n;i++) {
			if(i == I) continue;
			if(dist[i] > V + c[I][i]) {
				dist[i] = V + c[I][i];
				pq.push({-dist[i], i});
			}
		}
	}
	ans = d(sx, sy, ex, ey, 0);
	for(int i=1;i<=n;i++) {
		ans = min(ans, dist[i] + d(x[i], y[i], ex, ey, r[i]));
	}
	printf("%.12f\n",ans);
}
