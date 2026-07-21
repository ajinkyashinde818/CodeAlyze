#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
const int maxn = 1005;
using namespace std;
double max(double a, double b){
	if (a > b) return a;
	else return b;
}
int n; double x[maxn], y[maxn], r[maxn];
priority_queue <pair<double, int> > q;
double dis[maxn];
double D(int a, int b){
	double d = sqrt((x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]));
	return max(0, d - r[a] - r[b]);
}
bool vis[maxn];
void Dijkstra(int S){
	q.push(make_pair(0, S)); memset(vis, 0, sizeof vis);
	for (int i = 1; i <= n + 1; i++) dis[i] = 0x3f3f3f3f3f3f; dis[0] = 0;
	while (!q.empty()){
		int cur = q.top().second; q.pop();
		if (vis[cur]) continue; vis[cur] = 1;
		for (int i = 1; i <= n + 1; i++){
			if (i != cur && dis[i] > dis[cur] + D(cur, i)){
				dis[i] = dis[cur] + D(cur, i);
				if (!vis[i])
					q.push(make_pair(-dis[i], i));
			}
		}
	}
}
int main(){
	scanf("%lf%lf%lf%lf", x, y, x + 1, y + 1);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lf%lf%lf", x + i + 1, y + i + 1, r + i + 1);
	Dijkstra(0);
	printf("%.10lf\n", dis[1]);
	return 0;
}
