#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <utility>
#include <tuple>
#include <cctype>
#define INF 1e18
#define MOD 1000000007
#define PI 4*atan(1.0)
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(auto i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
 
typedef long long ll;
typedef long double ld;
using namespace std;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
const int SIZE=1005;
//int arr[SIZE]={};
//ここまでテンプレ
typedef double Weight;
struct Edge {
  int src, dst;
  Weight weight;
  Edge(int src, int dst, Weight weight) :
    src(src), dst(dst), weight(weight) { }
};
bool operator < (const Edge &e, const Edge &f) {
  return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
    e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
 
typedef vector<Weight> Array;
typedef vector<Array> Matrix;
 
void shortestPath(const Graph &g, int s,
    vector<Weight> &dist, vector<int> &prev) {
  int n = g.size();
  dist.assign(n, INF); dist[s] = 0;
  prev.assign(n, -1);
  priority_queue<Edge> Q; // "e < f" <=> "e.weight > f.weight"
  for (Q.push(Edge(-2, s, 0)); !Q.empty(); ) {
    Edge e = Q.top(); Q.pop();
    if (prev[e.dst] != -1) continue;
    prev[e.dst] = e.src;
    FOR(f,g[e.dst]) {
      if (dist[f->dst] > e.weight+f->weight) {
        dist[f->dst] = e.weight+f->weight;
        Q.push(Edge(f->src, f->dst, e.weight+f->weight));
      }
    }
  }
}
vector<int> buildPath(const vector<int> &prev, int t) {
  vector<int> path;
  for (int u = t; u >= 0; u = prev[u])
    path.push_back(u);
  reverse(path.begin(), path.end());
  return path;
}
int main(){
	cout<<setprecision(20);
	int sx,sy,gx,gy;
	cin>>sx>>sy>>gx>>gy;
	int N;
	cin>>N;
	int x[SIZE]={},y[SIZE]={},r[SIZE]={};
	for(int i=0;i<N;i++){
		cin>>x[i]>>y[i]>>r[i];
	}
	x[N]=sx,y[N]=sy,r[N]=0;
	x[N+1]=gx,y[N+1]=gy,r[N+1]=0;
	Graph G;
	for(int i=0;i<N+2;i++){
		Edges E;
		G.push_back(E);
	}
	for(int i=0;i<N+2;i++)for(int j=0;j<N+2;j++){
		double cost=max(0.0,sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2))-(double)(r[i]+r[j]));
		G[i].push_back(Edge(i,j,cost));
	}
	vector<Weight> dis;
	vector<int> prev;
 
	shortestPath(G,N,dis,prev);
	cout<<dis[N+1]<<endl;
	return 0;
}
