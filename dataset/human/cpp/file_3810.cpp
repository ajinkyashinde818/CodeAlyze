#include <bits/stdc++.h>
using namespace std;

int n;
double x[1010], y[1010], r[1010];
double g[1010][1010];
double d[1010];

int main() {
	cin >> x[0] >> y[0] >> x[1] >> y[1];
	r[0] = r[1] = 0.0;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> x[i + 2] >> y[i + 2] >> r[i + 2];
	}
	n += 2;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			g[i][j] = max(0.0, sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])) - r[i] - r[j]);
		}
	}
	
	using P = pair<double, int>;
	priority_queue<P, vector<P>, greater<P>> pq;
	fill_n(d, 1010, 1e10);
	d[0] = 0.0;
	pq.emplace(0.0, 0);
	while (pq.size()){
		double sum;
		int v;
		tie(sum, v) = pq.top(), pq.pop();
		if (d[v] < sum) continue;
		for (int u = 0; u < n; u++){
			if (d[u] > d[v] + g[v][u]){
				d[u] = d[v] + g[v][u];
				pq.emplace(d[u], u);
			}
		}
	}
	cout << fixed << setprecision(12) << d[1] << endl;
}
