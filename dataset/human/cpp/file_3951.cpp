#include<bits/stdc++.h>
using namespace std;
const double INF = 1e20;
using pdi = pair<double, int>;

struct graph
{
	int to;
	double cost;
};

double dis(long long s[], long long g[]) {
	double dx = s[0] - g[0], dy = s[1] - g[1];
	return max(0.0, sqrt(dx * dx + dy * dy) - s[2] - g[2]);
}

int main() {
	long long barrier[1010][3];
	for (int i = 0; i < 2; i++)
	{
		cin >> barrier[i][0] >> barrier[i][1];
		barrier[i][2] = 0;
	}
	int N; cin >> N;
	for (int i = 2; i < N+2; i++)
	{
		cin >> barrier[i][0] >> barrier[i][1] >> barrier[i][2];
	}

	vector<graph> g[N+2];
	for (int i = 0; i < N+2; i++)
	{
		for (int j = i+1; j < N+2; j++)
		{
			g[i].push_back(graph{j, dis(barrier[i], barrier[j])});
			g[j].push_back(graph{i, dis(barrier[i], barrier[j])});
		}
	}

	vector<double> dist(N+2, INF);
	dist[0] = 0.0;
	priority_queue<pdi, vector<pdi>, greater<pdi>> que;
	que.emplace(dist[0], 0);
	while (!que.empty())
	{
		double cost;
		int idx;
		tie(cost, idx) = que.top(); que.pop();
		if(dist[idx] < cost) continue;
		for (auto &e : g[idx])
		{
			auto next_cost = cost + e.cost;
			if(dist[e.to] <= next_cost) continue;
			dist[e.to] = next_cost;
			que.emplace(dist[e.to], e.to);
		}
	}
	cout << fixed << setprecision(10) << dist[1] << endl;
	return 0;
}
