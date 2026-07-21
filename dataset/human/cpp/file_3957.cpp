#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <iomanip>
using namespace std;

struct edge{
	int to;
	double cost;

	edge(int to, double cost){
		this->to = to;
		this->cost = cost;
	}
};

int main(){
	int xs, ys, xt, yt, n;
	cin >> xs >> ys >> xt >> yt >> n;
	double x[n], y[n], r[n];
	for(int i = 0; i < n; i++) cin >> x[i] >> y[i] >> r[i];
	vector<vector<edge>> v(n + 2);
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			double dist = max(0.0, hypot(x[i] - x[j], y[i] - y[j]) - r[i] - r[j]);
			v[i].emplace_back(edge(j, dist));
			v[j].emplace_back(edge(i, dist));
		}
	}
	for(int i = 0; i < n; i++){
		double dist = max(0.0, hypot(xs - x[i], ys - y[i]) - r[i]);
		v[n].emplace_back(edge(i, dist));
	}
	for(int i = 0; i < n; i++){
		double dist = max(0.0, hypot(xt - x[i], yt - y[i]) - r[i]);
		v[i].emplace_back(edge(n + 1, dist));
	}
	{
		double dist = hypot(xs - xt, ys - yt);
		v[n].emplace_back(edge(n + 1, dist));
	}
	vector<double> dist(n + 2, 1e20);
	dist[n] = 0;
	priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
	pq.emplace(make_pair(dist[n], n));
	while(!pq.empty()){
		pair<double, int> p = pq.top();
		pq.pop();
		int now = p.second;
		for(edge &e:v[now]){
			if(dist[now] + e.cost < dist[e.to]){
				dist[e.to] = dist[now] + e.cost;
				pq.emplace(make_pair(dist[e.to], e.to));
			}
		}
	}
	cout << fixed << setprecision(10) << dist[n + 1] << endl;
}
