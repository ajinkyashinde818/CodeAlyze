#include<cstring>
#include<string>
#include<vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<list>
#include<set>
#include<map>
#include<complex>
#include<sstream>
#include<climits>
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = (Y)-1;(X) >=0;--(X))
#define all(X) (X).begin(),(X).end()
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double, int> pbi;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

const int MAX_N = 1000;
ll N, xs, ys, xt, yt;
ll x[MAX_N+1], y[MAX_N+1], r[MAX_N+1];


                            
struct edge { 
  int to; 
  double cost; 
  edge(int u, double c) {
    to = u; cost = c;
  };
};

const int MAX_V = MAX_N+2;
const double INF = 1e12;

int V;
vector<edge> G[MAX_V];
double d[MAX_V];

void dijkstra(int s) {
  for (int i = 0; i <= N+1; ++i) d[i] = INF;
  priority_queue<pbi, vector<pbi>, greater<pbi> > pque;
  d[s] = 0;
  pque.push(pbi(0, s));


  while (!pque.empty()) {
    pbi p = pque.top(); pque.pop();
    int v = p.second;
    if (d[v] < p.first) continue;
    for (int i = 0; i < (int)G[v].size(); ++i) {
      edge e = G[v][i];
      if (d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost; 
        pque.push(pbi(d[v]+ e.cost, e.to));
      }
    }
  }
}


int main() {
  cin >>  xs >> ys >> xt >> yt;
  cin >> N;
  for (int i = 1; i <= N; ++i) cin >> x[i] >> y[i] >> r[i];

  for (int i = 1; i <= N; ++i) {
    double dist = sqrt((xs-x[i])*(xs-x[i]) + (ys-y[i])*(ys-y[i]));
    if (dist <= (double)r[i]) G[0].push_back(edge(i, 0));
    else G[0].push_back(edge(i, dist-(double)r[i]));
  }

  for (int i = 1; i <= N; ++i) {
    for (int j = i+1; j <= N; ++j) {
      double dist = sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
      if (dist <= double(r[i]+r[j])) {
        G[i].push_back(edge(j, 0));
        G[j].push_back(edge(i, 0));
      } else {
        G[i].push_back(edge(j, dist-(double)r[i]-(double)r[j]));
        G[j].push_back(edge(i, dist-(double)r[i]-(double)r[j]));

      }
    }
  }
  for (int i = 1; i <= N; ++i) {
    double dist = sqrt((xt-x[i])*(xt-x[i]) + (yt-y[i])*(yt-y[i]));
    if (dist <= (double)r[i]) G[i].push_back(edge(N+1, 0));
    else G[i].push_back(edge(N+1, dist-(double)r[i]));
  }

  double dist = sqrt((xs-xt)*(xs-xt) + (ys-yt)*(ys-yt));
  G[0].push_back(edge(N+1,dist));

  /*
  for (int i = 0; i <= N+1; ++i) {
    cout << "v = " << i << endl;
    for (int k = 0; k < G[i].size(); ++k) {
      printf("(to, cost) = (%d, %.10f), ", G[i][k].to, G[i][k].cost);
    }
    cout << endl;
  }
  */

  dijkstra(0);

  printf("%.13f\n", d[N+1]);

  return 0;
}
