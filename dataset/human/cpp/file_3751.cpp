#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <numeric>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <complex>
#include <fstream>
#include <bitset>

using namespace std;

#define FOR(i,a,b) for(long long i=(a);i<(b);i++)
#define REP(i,N) for(long long i=0;i<(N);i++)
#define ALL(s) (s).begin(),(s).end()
#define fi first
#define se second

#define PI acos(-1.0)
#define INF 1e7+9
#define MOD 1000000007
#define EPS 1e-10
#define MAX_N 100100
#define MAX_M 100100

typedef long long ll;
typedef pair<ll, ll> P;
typedef vector<ll> V;

struct edge{
	int to;
	double cost;
	edge(int _to, double _cost) :to(_to), cost(_cost){}
};

vector<edge> G[1010];
double xs, ys, xt, yt;
int n;
double d[1010];

void dijkstra(){
	REP(i, 1010)d[i] = 1e18;
	d[0] = 0;

	typedef pair<double, int> PD;
	priority_queue<PD, vector<PD>, greater<PD>> que;
	que.push(pair<double, int>(0, 0));

	while (!que.empty()){
		pair<double, int> p = que.top();
		que.pop();
		int v = p.second;
		if (d[v] < p.first)continue;
		for (int i = 0; i < G[v].size(); i++){
			edge e = G[v][i];
			if (d[e.to] > d[v] + e.cost){
				d[e.to] = d[v] + e.cost;
				que.push(pair<double, int>(d[e.to], e.to));
			}
		}
	}
}

int main(){
	cin >> xs >> ys >> xt >> yt >> n;
	vector<double> x(1010), y(1010), r(1010);
	x[0] = xs;
	y[0] = ys;
	r[0] = 0;
	x[n + 1] = xt;
	y[n + 1] = yt;
	r[n + 1] = 0;
	FOR(i, 1, n + 1){
		cin >> x[i] >> y[i] >> r[i];
	}
	REP(i, n + 2){
		REP(j, n + 2){
			if (i == j)continue;
			G[i].push_back(
				edge(j, max(0.0, sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j])) - (r[i] + r[j]))));
			//cout << i << " " << j << sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j])) - (r[i] + r[j]) << endl;
		}
	}


	dijkstra();
	printf("%.10lf\n", d[n + 1]);
}
