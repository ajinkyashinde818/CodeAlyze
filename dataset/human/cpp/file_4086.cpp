#include<bits/stdc++.h>
using namespace std;

typedef pair<double,int> P;
 
vector<vector<double>> edges(1010,vector<double>(1010,0));
vector<double> dist(1010,10000000000);

void dijkstra(int n) {
	priority_queue<P,vector<P>,greater<P>> que;
	dist[0] = 0;
	que.push(P(0.0,0));
 
	while (!que.empty()) {
		P p = que.top();
		que.pop();

		int v = p.second;
		if (dist[v] < p.first) continue;
		for (int i = 0;i < n;++i) {
			double e = edges[v][i];
			if (dist[i] > dist[v]+e) {
				dist[i] = dist[v]+e;
				que.push(P(dist[i],i));
			}
		}
	}
}

int main() {
	double x[1010],y[1010],r[1010],xt,yt;
	int n;
	cin >> x[0] >> y[0] >> xt >> yt >> n;
	for (int i = 1;i <= n;++i) cin >> x[i] >> y[i] >> r[i];
	x[n+1] = xt;
	y[n+1] = yt;
	r[0] = r[n+1] = 0;

	for (int i = 0;i < n+2;++i) {
		for (int j = 0;j < n+2;++j) {
			edges[i][j] = max(0.0,sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))-r[i]-r[j]);
		}
	}

	dijkstra(n+2);

	cout << setprecision(12) << dist[n+1] << endl;

	return 0;
}
