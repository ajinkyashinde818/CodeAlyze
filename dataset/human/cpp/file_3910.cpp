#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, long double> P;

const ll INF = 1e12;
ll n, xt, yt;
ll x[1100], y[1100], r[1100];
vector<P> edge[1100];
long double dist[1100];

void dijkstra(ll s) {
  priority_queue<P, vector<P>, greater<P>> pq;
 
  for (ll i = 0; i <= n+1; i++) {
    dist[i] = INF;
  }
 
  dist[s] = 0;
  pq.push(pair<long double, ll>(0, s));
 
  while (pq.size()) {
    P p = pq.top();
    pq.pop();
    ll u = p.second;
    if (dist[u] < p.first) continue;
    for (P p: edge[u]) {
      ll v = p.first;
      long double cost = p.second;
      if (dist[v] > dist[u] + cost) {
        dist[v] = dist[u] + cost;
        pq.push(pair<long double, ll>(dist[v], v));
      }
    }
  }
}

int main() {
  cin >> x[0] >> y[0] >> xt >> yt;
  cin >> n;
  x[n+1] = xt;
  y[n+1] = yt;

  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i] >> r[i];
  }
  
  for (int i = 0; i <= n; i++) {
    for (int j = i+1; j <= n+1; j++) {
      long double dist = sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
      dist = max(0.0L, dist-r[i]-r[j]);
      edge[i].push_back(P(j, dist));
      edge[j].push_back(P(i, dist));
    }
  }
  
  dijkstra(0);

  cout << fixed << setprecision(12) << dist[n+1] << endl;
  return 0;
}
