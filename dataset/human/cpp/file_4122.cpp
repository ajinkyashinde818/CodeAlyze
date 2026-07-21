#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <memory.h>
#include <cmath>
#include <queue>


using namespace std;

typedef long long ll;

const int N = 2010;

struct point{
	double x , y;

	bool operator==(const point &rhs)const{
		return fabs(rhs.x - x) < 1e-9 && fabs(rhs.y - y) < 1e-9;
	}
};
int n;

point s , t , cir[N];

double r[N];

double dist(point s , point t){
	return sqrt((s.x - t.x) * (s.x - t.x) + (s.y - t.y) * (s.y - t.y));
}

vector< pair<int,double> > g[N];

double cost[N];

bool vis[N];

struct state{
	int u;
	double cost;

	state(int _u,double _cost){
		u = _u;
		cost = _cost;
	}
	bool operator<(const state &rhs) const{
		return cost > rhs.cost;
	}
};
int main(){
	//freopen("input.txt","r",stdin);
	scanf("%lf%lf%lf%lf",&s.x,&s.y,&t.x,&t.y);
	scanf("%d",&n);
	for(int i = 0 ; i < N ; i++)
		cost[i] = 1e12;

	for (int i = 1; i <= n; ++i){
		scanf("%lf%lf",&cir[i].x,&cir[i].y);
		scanf("%lf",&r[i]);
	}
	for (int i = 1; i <= n; ++i){
		double take = dist(s,cir[i]);
		take -= r[i];
		take = max(0.000000,take);
		g[0].push_back(make_pair(i,take));
		g[i].push_back(make_pair(0,take));
	}
	g[0].push_back(make_pair(n+1,dist(s,t)));
	g[n+1].push_back(make_pair(0,dist(s,t)));
	for (int i = 1; i <= n; ++i){
		double take = dist(t,cir[i]);
		take -= r[i];
		take = max(0.000000,take);
		g[n + 1].push_back(make_pair(i,take));
		g[i].push_back(make_pair(n + 1,take));
	}
	for (int i = 1; i <= n; ++i){
		for (int j = i + 1; j <= n; ++j){
			double take = dist(cir[i],cir[j]);
			take -= r[i] + r[j];
			take = max(0.000000,take);
			g[i].push_back(make_pair(j,take));
			g[j].push_back(make_pair(i,take));
		}
	}
	priority_queue< state > q;
	q.push(state(0,0));
	cost[0] = 0;
	while(!q.empty()){
		state src = q.top();
		q.pop();
		if(vis[src.u])
			continue;
		vis[src.u] = 1;

		cost[src.u] =  src.cost;
		for (int i = 0; i < g[src.u].size(); ++i){
			int v = g[src.u][i].first;

			double newCost = src.cost + g[src.u][i].second;
			if(newCost < cost[v]){
				cost[v] = newCost;
				q.push(state(v,newCost));
			} 
		}
	}
	printf("%.9lf\n",cost[n + 1] );
	return 0;
}
