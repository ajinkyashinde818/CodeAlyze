#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;

#define INF 1e30

struct ST {
  double x, y ,r;
};

int nNode;
double G[1005][1005];

double dist(const ST& a, const ST& b){
  double d = sqrt( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) );
  if(d <= a.r + b.r) return 0;
  return d - (a.r + b.r);
}

double dijkstra(int start, int goal){
  int nVisit = 0;
  bool visited[1005];
  double cost[1005];
 
  for(int i=0; i<nNode; i++){
    cost[i] = INF;
    visited[i] = false;
  }
  cost[start] = 0;
 
  while(nVisit != nNode){
    int minPos;
    double minVal = INF;
    
    for(int i=0; i<nNode; i++){
      if(minVal>cost[i] && !visited[i]){
        minVal = cost[i];
        minPos = i;
      }
    }
 
    if(minVal > INF-1) break;
    if(minPos == goal) return minVal;
    
    visited[minPos] = true;
    nVisit++;
 
    for(int i=0; i<nNode; i++){
      if(cost[i]>cost[minPos]+G[minPos][i]){
        cost[i] = cost[minPos]+G[minPos][i];
      }
    }
  }
}

int main(){
  double xs, ys, xt, yt;
  int N;
  cin >> xs >> ys >> xt >> yt;
  cin >> N;
  vector<ST> v;
  rep(i,N){
    double x, y, r;
    cin >> x >> y >> r;
    v.push_back((ST){x,y,r});
  }
  v.push_back((ST){xs,ys,0});
  v.push_back((ST){xt,yt,0});

  rep(i,1005) rep(j,1005) G[i][j] = INF;

  rep(i,N+2){
    REP(j,i,N+2){
      double d = dist(v[i], v[j]);
      G[i][j] = d;
      G[j][i] = d;
    }
  }
  nNode = N+2;

  printf("%.12lf\n", dijkstra(N, N+1));
  
  return 0;
}
