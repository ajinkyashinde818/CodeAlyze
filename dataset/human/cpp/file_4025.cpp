#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <functional>
#include <algorithm>

using namespace std;

#define rep(i,j) REP((i), 0, (j))
#define REP(i,j,k) for(int i=(j);(i)<(k);++i)
#define BW(a,x,b) ((a)<=(x)&&(x)<=(b))
#define ALL(v) (v).begin(), (v).end()
#define LENGTHOF(x) (sizeof(x) / sizeof(*(x)))
#define AFILL(a, b) fill((int*)a, (int*)(a + LENGTHOF(a)), b)
#define SQ(x) ((x)*(x))
#define Mod(x, mod) (((x)+(mod)%(mod))
#define MP make_pair
#define PB push_back
#define Fi first
#define Se second
#define INF (1LL<<60)
#define EPS 1e-10
#define MOD 1000000007

typedef long long ll;
typedef pair<ll, ll> pi;
typedef pair<double, int>P;
typedef pair<pi, ll> pii;
typedef vector<int> vi;
typedef queue<int> qi;


int N;
double d[1024];
vector<P>V[1024];

void dijkstra(int s)
{
  fill(d, d+1024, (double)INF);
  priority_queue<P, vector<P>, greater<P> >Q;
  d[s] = 0.0;
  Q.push(make_pair(0, s));

  while(!Q.empty()){
    P p = Q.top(); Q.pop();
    double dist = p.first;
    int v = p.second;
    if(dist > d[v]) continue;
    for(int i=0;i<V[v].size();i++){
      P next = V[v][i];
      if(dist+next.first < d[next.second]){
	d[next.second] = dist+next.first;
	Q.push(make_pair(d[next.second], next.second));
      }
    }
  }
}

int main()
{
  vector<pii>B;
  ll xs, ys, xt, yt;
  cin >> xs >> ys >> xt >> yt;
  B.push_back(make_pair(make_pair(xs, ys), 0LL));
  cin >> N;
  rep(i, N){
    ll x, y , r;
    cin >> x >> y >> r;
    B.push_back(make_pair(make_pair(x, y), r));
  }
  B.push_back(make_pair(make_pair(xt, yt), 0LL));

  for(int i=0;i<N+2;i++){
    for(int j=i+1;j<N+2;j++){
      pi s, t; s = B[i].first; t = B[j].first;
      ll sr, tr; sr = B[i].second; tr = B[j].second;
      double dist = max(0.0, sqrt((s.first-t.first)*(s.first-t.first) + (s.second-t.second)*(s.second-t.second)) - (double)(sr+tr));
      V[i].push_back(make_pair(dist, j));
      V[j].push_back(make_pair(dist, i));
    }
  }

  dijkstra(0);

  printf("%.10lf\n", d[N+1]);
  return 0;
}
