#include <bits/stdc++.h>
using namespace std;
const int maxn = 1020;
long long x[maxn], y[maxn], r[maxn];
long double distance(int i, int j){
	long long delta = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
	if(delta <= (r[i] + r[j]) * (r[i] + r[j])) return 0.0L;
	return sqrtl(delta) - r[i] - r[j];
}
long double dist[maxn];
int seen[maxn];
int main(){
	cin >> x[0] >> y[0] >> x[1] >> y[1];
	int n; cin >> n;
	for(int i = 0; i < n; i++) cin >> x[i+2] >> y[i+2] >> r[i+2];
	n += 2;
	for(int i = 0; i < n; i++) dist[i] = 1e18;
	dist[0] = 0;
	for(int i = 0; i < n; i++){
		int now = -1;
		for(int j = 0; j < n; j++) if(!seen[j] && (now == -1 || dist[j] < dist[now])) now = j;
		seen[now] = 1;
		for(int j = 0; j < n; j++) dist[j] = min(dist[j], dist[now] + distance(now, j));
	}
	cout << fixed << setprecision(12) << dist[1] << endl;
	return 0;
}
