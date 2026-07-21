#include<bits/stdc++.h>
using namespace std;
const int maxn = 1005;
struct lpl{double x, y, r;}node[maxn];
struct ld{
	int num; double d;
	bool operator < (const ld &A)const{return d > A.d;}
};
int n, s, t;
double dis[maxn][maxn];
double ddd[maxn];
priority_queue<ld> q;
bool vis[maxn];

inline double Dis(double x1, double y1, double x2, double y2){return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));}

inline void dijkstra(){
	q.push((ld){s, 0});
	while(!q.empty()){
		ld now = q.top(); q.pop(); if(vis[now.num]) continue;
		vis[now.num] = true; 
		if(now.num == t){printf("%.10lf", now.d); return;}
		for(int i = 1; i <= t; ++i){
			if(i == now.num) continue;
			if(ddd[i] > now.d + dis[now.num][i]){
				ddd[i] = now.d + dis[now.num][i];
				q.push((ld){i, ddd[i]});
			}
		}
	}
}

inline void check(){
	for(int i = 0; i <= t; ++i){
		for(int j = i + 1; j <= t; ++j){
			printf("dis[%d][%d] = %lf\n", i, j, dis[i][j]);
		}
	}
}

int main()
{
	//freopen("lpl.in", "r", stdin);
	lpl qaq;
	scanf("%lf%lf%lf%lf", &node[s].x, &node[s].y, &qaq.x, &qaq.y); scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%lf%lf%lf", &node[i].x, &node[i].y, &node[i].r);
	t = n + 1; node[t] = qaq;
	for(int i = 1; i <= t; ++i) ddd[i] = 1e17;
	for(int i = 0; i <= t; ++i)
		for(int j = 0; j <= t; ++j)
			dis[i][j] = 1e17;
	for(int i = 1; i <= n; ++i){
		dis[s][i] = max(0.0, Dis(node[s].x, node[s].y, node[i].x, node[i].y) - node[i].r);
		dis[i][t] = max(0.0, Dis(node[t].x, node[t].y, node[i].x, node[i].y) - node[i].r);	
	}
	dis[s][t] = max(0.0, Dis(node[s].x, node[s].y, node[t].x, node[t].y));
	//check();
	for(int i = 1; i <= n; ++i)
		for(int j = i + 1; j <= n; ++j)
			dis[i][j] = dis[j][i] = max(0.0, Dis(node[i].x, node[i].y, node[j].x, node[j].y) - node[i].r - node[j].r);
	
	dijkstra();
	return 0;
}
