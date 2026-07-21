#include <bits/stdc++.h>

using namespace std;

struct point {
	double x,y;
};

struct circle {
	point p;
	double r;
};

double dist[1002][1002];

double f(point &a, point &b) {
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double g(circle &a, circle &b) {
	return max(0.0,f(a.p,b.p)-a.r-b.r);
}

int main() {
	point s,t; cin >> s.x >> s.y >> t.x >> t.y;
	int n; cin >> n;
	vector<circle> cs(n);
	for(int i=0;i<n;++i) cin >> cs[i].p.x >> cs[i].p.y >> cs[i].r;
	for(int i=0;i<n;++i) {
		for(int j=i+1;j<n;++j) {
			dist[i][j]=dist[j][i]=g(cs[i],cs[j]);
		}
		dist[i][n]=dist[n][i]=max(0.0,f(s,cs[i].p)-cs[i].r);
		dist[i][n+1]=dist[n+1][i]=max(0.0,f(t,cs[i].p)-cs[i].r);
	}
	dist[n][n+1]=dist[n+1][n]=f(s,t);
	for(int k=0;k<n+2;++k)
		for(int i=0;i<n+2;++i)
			for(int j=0;j<n+2;++j)
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
    printf("%.10f\n",dist[n][n+1]);
	
	return 0;
}
