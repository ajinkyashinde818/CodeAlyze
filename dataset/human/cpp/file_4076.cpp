#include <bits/stdc++.h>

using namespace std;

int x[1111], y[1111], r[1111];
double d[1111];
vector<pair<int, double> > g[1111];
int n;

long long sqr(int x){
	return 1ll * x * x;
}

double dist(int a, int b, int c, int d){
	return sqrt(sqr(a - c) + sqr(b - d));
}

int main(){
//	freopen("input.inp", "r", stdin);
	int xx, yy;
	scanf("%d%d%d%d",&x[0],&y[0],&xx,&yy);
	scanf("%d",&n);
	++n;
	x[n] = xx;
	y[n] = yy;
	for(int i = 1; i < n; ++i) scanf("%d%d%d",&x[i],&y[i],&r[i]);
	for(int i = 0; i <= n; ++i){
		for(int j = i + 1; j <= n; ++j){
			double d = dist(x[i], y[i], x[j], y[j]) - r[i] - r[j];
			if (d < 0) d = 0;
			g[i].push_back(make_pair(j, d));
			g[j].push_back(make_pair(i, d));
		}
	}
	set<pair<double, int> > s;
	s.insert(make_pair(0, 0));
	for(int i = 1; i <= n; ++i) d[i] = 1e20;
	while (!s.empty()){
		pair<double, int> cur = *s.begin();
		s.erase(s.begin());
		int u = cur.second;
		if (abs(d[u] - cur.first) > 1e-7) continue;
		for(int i = 0; i < g[u].size(); ++i){
			int v = g[u][i].first;
			double c = g[u][i].second;
			if (d[v] > d[u] + c){
				d[v] = d[u] + c;
				s.insert(make_pair(d[v], v));
			}
		}
	}
	printf("%.15lf",d[n]);
	return 0;
}
