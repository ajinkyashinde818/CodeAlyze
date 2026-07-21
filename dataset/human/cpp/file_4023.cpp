#include <bits/stdc++.h>
using namespace std;

constexpr double eps = 1e-10;
constexpr double inf = 1e18;
int n;
class point{
public:
	double x, y;
	point(double _x, double _y) : x(_x), y(_y) {}
};
vector<point> p;
vector<int> r;

class Edge{
public:
	double cost;
	int from, to;
	Edge(double c, int f, int t){
		cost = c;
		from = f;
		to = t;
	}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

bool operator < (const Edge &e, const Edge &f){
	return e.cost != f.cost ? e.cost > f.cost : e.from != f.from ? e.from < f.from : e.to < f.to;
}
void dijkstra(int s, const Graph &g, vector<double> &dist){
	int V = g.size();
	dist = vector<double>(V, inf);
	dist[s] = 0;
	priority_queue<Edge> q;
	q.push(Edge(0, s, s));
	while(!q.empty()){
		Edge e = q.top();
		q.pop();
		if(dist[e.to] < e.cost) continue;
		for(int i=0; i<(int)g[e.to].size(); ++i){
			Edge f = g[e.to][i];
			if(dist[f.to] > dist[e.to] + f.cost){
				dist[f.to] = dist[e.to] + f.cost;
				q.push(Edge(dist[f.to], s, f.to));
			}
		}
	}
}

double norm(double x, double y){
	return sqrt(x*x + y*y);
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int a, b;
	cin >> a >> b;
	point s(a, b);
	cin >> a >> b;
	point t(a, b);
	cin >> n;
	for(int i=0; i<n; ++i){
		int tx, ty, tr;
		cin >> tx >> ty >> tr;
		p.push_back(point(tx, ty));
		r.push_back(tr);
	}
	Graph g(n+2);
	for(int i=0; i<n; ++i){
		for(int j=i+1; j<n; ++j){
			double d = norm(p[i].x-p[j].x, p[i].y-p[j].y);
			double e = d + eps < r[i]+r[j] ? 0 : d-r[i]-r[j];
			g[i].push_back(Edge(e, i, j));
			g[j].push_back(Edge(e, j, i));
		}
		double d = norm(p[i].x-s.x, p[i].y-s.y) - r[i];
		if(d <= eps) d = 0.0;
		g[n].push_back(Edge(d, n, i));
		d = norm(p[i].x-t.x, p[i].y-t.y) - r[i];
		if(d <= eps) d = 0.0;
		g[i].push_back(Edge(d, i, n+1));
	}
	vector<double> dist;
	dijkstra(n, g, dist);
	double ans = norm(s.x-t.x, s.y-t.y);
	ans = min(ans, dist[n+1]);
	cout << fixed << setprecision(15) << ans << "\n";
}
