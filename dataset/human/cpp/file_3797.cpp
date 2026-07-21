#include <bits/stdc++.h>

using namespace std;

struct Node {
    int at;
    double cost; 
    int prev;
    Node(int at, double cost, int prev) : at(at), cost(cost), prev(prev) {}
    bool operator>(const Node &s) const {
        if (cost != s.cost) return cost > s.cost;
        if (prev != s.prev) return prev > s.prev; //最短経路を辞書順最小にする(省略可)
        return at > s.at;
    }
};

struct Edge {
  int to;
  double cost;  
  Edge(int to, double cost) : to(to), cost(cost) {}  
};

typedef vector<vector<Edge> > AdjList; //隣接リスト

const double INF = 1e20;
const int NONE = -1;

AdjList graph;

//sは始点、mincは最短経路のコスト、Prevは最短経路をたどる際の前の頂点
void dijkstra(int s, vector<double> &minc, vector<int> &Prev){ 
    priority_queue<Node, vector<Node>, greater<Node> > pq;
    pq.push(Node(s, 0, NONE));
    while(!pq.empty()) {
        Node x = pq.top();
        pq.pop();
        if (minc[x.at] != INF) continue;
        minc[x.at] = x.cost;
        Prev[x.at] = x.prev;
        for(int i = 0; i < (int)graph[x.at].size(); i++) {
        	Edge e = graph[x.at][i];
            if (minc[e.to] == INF) {
            	pq.push(Node(e.to, x.cost + e.cost, x.at));
            }
        }
    }
}


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	double xs, ys, xt, yt;
	int n;
	cin >> xs >> ys >> xt >> yt >> n;
	vector<double> x(n), y(n), r(n);
	graph = AdjList(n + 2);
	double cost;
	cost = sqrt((xs - xt) * (xs - xt) + (ys - yt) * (ys - yt));
	graph[n].emplace_back(n + 1, cost);
	graph[n + 1].emplace_back(n, cost);
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i] >> r[i];
		cost = max(0.0, sqrt((xs - x[i]) * (xs - x[i]) + (ys - y[i]) * (ys - y[i])) - r[i]);
		graph[i].emplace_back(n, cost);
		graph[n].emplace_back(i, cost);
		cost = max(0.0, sqrt((xt - x[i]) * (xt - x[i]) + (yt - y[i]) * (yt - y[i])) - r[i]);
		graph[i].emplace_back(n + 1, cost);
		graph[n + 1].emplace_back(i, cost);
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			cost = max(0.0, sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])) - r[i] - r[j]);
			graph[i].emplace_back(j, cost);
			graph[j].emplace_back(i, cost);
		}
	}

	vector<double> minc(n + 2, INF);
	vector<int> Prev(n + 2, NONE);

	dijkstra(n, minc, Prev);
	cout << fixed << setprecision(15) << minc[n + 1] << endl;
	return 0;
}
