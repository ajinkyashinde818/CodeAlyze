#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;
const double Inf = 2.83e9;

int main(){
  long long xs,ys,xt,yt;
  cin >> xs >> ys >> xt >> yt;
  int N;
  cin >> N;
  vector<long long> x(N+2), y(N+2), r(N+2);
  x[0] = xs; y[0] = ys; r[0] = 0;
  x[N+1] = xt; y[N+1] = yt; r[N+1] = 0;
  for(int i = 1; i <= N; i++){
    cin >> x[i] >> y[i] >> r[i];
  }
  vector<vector<double> > edge(N+2, vector<double>(N+2, -1.0));
  for(int i = 0; i < N+2; i++){
    for(int j = i+1; j < N+2; j++){
      edge[i][j] = max(sqrt((x[j] - x[i]) * (x[j] - x[i]) + (y[j] - y[i]) * (y[j] - y[i])) - (r[i] + r[j]), 0.0);
      edge[j][i] = edge[i][j];
    }
  }

  vector<double> cost(N+2, Inf);
  cost[0] = 0.0;
  priority_queue<pair<double, int>, vector<pair<double, int> >, greater<pair<double, int> > >  q;
  q.push({0.0, 0});

  vector<bool> check(N+2, false);

  while(!q.empty()){
    auto now_pair = q.top();
    double ncost = now_pair.first; int nid = now_pair.second;
    q.pop();
    if(check[nid]) continue;
    check[nid] = true;
    cost[nid] = ncost;

    for(int i = 0; i < N+2; i++){
      if(!check[i]){
        if(cost[nid] + edge[nid][i] < cost[i]){
          cost[i] = cost[nid] + edge[nid][i];
          q.push({cost[i], i});
        }
      }
    }
  }

  printf("%.9lf\n",cost[N+1]);
}
