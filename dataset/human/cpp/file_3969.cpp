#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <vector>

using namespace std;
int main(){
  long long int xs, ys, xt, yt;
  scanf("%lld%lld%lld%lld", &xs, &ys, &xt, &yt);
  int N;
  scanf("%d", &N);
  vector<pair<pair<double, double>, double> > xyr(N+2, pair<pair<double,double>, double>());
  xyr[0].first.first = xs;
  xyr[0].first.second = ys;
  xyr[0].second = 0;
  xyr[N+1].first.first = xt;
  xyr[N+1].first.second = yt;
  xyr[N+1].second = 0;
  for (int i = 1; i <= N; i++){
    scanf("%lf%lf%lf", &(xyr[i].first.first), &(xyr[i].first.second), &(xyr[i].second));
  }

  vector<vector<double> > edge(N+2, vector<double>(N+2, 0));
  for (int i = 0; i < N+2; i++){
    for (int j = 0; j < N+2; j++){
      edge[i][j] = sqrt((xyr[i].first.first-xyr[j].first.first)*(xyr[i].first.first-xyr[j].first.first)+(xyr[i].first.second-xyr[j].first.second)*(xyr[i].first.second-xyr[j].first.second)) - xyr[i].second-xyr[j].second;
      if (edge[i][j] < 0){
        edge[i][j] = 0;
      }
    }
  }
  vector<double> dist(N+2, 0);
  for (int i = 0; i < N+2; i++){
    dist[i] = edge[0][i];
  }  
  set<int> already;
  already.insert(0);
  while(already.size() < (N+2)){
    int minindex = 0;
    double mindist = pow(10.0, 18.0)+1.0;
    for (int i = 0; i < N+2; i++){
      if (already.find(i) == already.end()){
        if (mindist > dist[i]){
          minindex = i;
          mindist = dist[i];
	}
      }
    }
    if (minindex == 0){
      break;
    }
    already.insert(minindex);
    for (int i = 0; i < N+2; i++){
      if (already.find(i) == already.end()){
        dist[i] = min(dist[minindex]+edge[minindex][i], dist[i]);
      }
    }
  }
  printf("%.18lf\n", dist[N+1]);
  return 0;
}
