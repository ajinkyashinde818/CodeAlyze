#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstdio>
using namespace std;
vector<double> dijkstra(int N, vector< vector<double> > G, int s){
  double INF = (1e12);
  priority_queue< pair<double,int> > wait;
  vector<double> result(N,INF);
  result[s] = 0.0;
  wait.push(make_pair(0.0,s));
  while(!wait.empty()){
    int nowpoint = wait.top().second;
    double nowcost = -wait.top().first;
    wait.pop();
    for(int i = 0; i < N; ++i){
      double nextcost = nowcost + G[nowpoint][i];
      if(nextcost < result[i]){
	result[i] = nextcost;
	wait.push(make_pair(-nextcost,i));
      }
    }
  }
  return result;
}

int main(){
  double x, y, xt, yt;
  int N;
  double INF = (1e12);
  cin >> x >> y >> xt >> yt >> N;
  vector< vector<double> > V(N+2,vector<double>(N+2,INF));
  double X[N], Y[N], R[N];
  for(int i = 0; i < N; ++i){
    cin >> X[i] >> Y[i] >> R[i];
  }
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
      V[i][j] = max(0.0,sqrt((X[i]-X[j])*(X[i]-X[j])+(Y[i]-Y[j])*(Y[i]-Y[j]))-R[i]-R[j]);
    }
  }
  for(int i = 0; i < N; ++i){
    V[i][N] = max(0.0,sqrt((X[i]-x)*(X[i]-x)+(Y[i]-y)*(Y[i]-y))-R[i]);
    V[N][i] = V[i][N];
    V[i][N+1] = max(0.0,sqrt((X[i]-xt)*(X[i]-xt)+(Y[i]-yt)*(Y[i]-yt))-R[i]);
    V[N+1][i] = V[i][N+1];
  }
  V[N][N+1] = sqrt((x-xt)*(x-xt)+(y-yt)*(y-yt));
  V[N+1][N] = V[N][N+1];
  printf("%.10f\n",dijkstra(N+2,V,N)[N+1]);
  return 0;
}
