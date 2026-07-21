#include <bits/stdc++.h>
using namespace std;
double INF = 1000000000000000;
double dist(pair<double, double> P, pair<double, double> Q){
  return sqrt(pow(Q.first - P.first, 2) + pow(Q.second - P.second, 2));
}
int main(){
  cout << fixed << setprecision(20);
  double xs, ys, xt, yt;
  cin >> xs >> ys >> xt >> yt;
  int N;
  cin >> N;
  vector<double> x(N), y(N), r(N);
  for (int i = 0; i < N; i++){
    cin >> x[i] >> y[i] >> r[i];
  }
  x.push_back(xs);
  y.push_back(ys);
  r.push_back(0);
  x.push_back(xt);
  y.push_back(yt);
  r.push_back(0);
  N += 2;
  vector<vector<pair<double, int>>> E(N);
  for (int i = 0; i < N; i++){
    for (int j = i + 1; j < N; j++){
      pair<double, double> P = make_pair(x[i], y[i]);
      pair<double, double> Q = make_pair(x[j], y[j]);
      double d = dist(P, Q);
      if (d <= r[i] + r[j]){
        E[i].push_back(make_pair(0, j));
        E[j].push_back(make_pair(0, i));
      } else {
        double d2 = d - r[i] - r[j];
        E[i].push_back(make_pair(d2, j));
        E[j].push_back(make_pair(d2, i));
      }
    }
  }
  vector<double> d(N, INF);
  priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> Q;
  Q.push(make_pair(0, N - 2));
  while (!Q.empty()){
    double c = Q.top().first;
    int v = Q.top().second;
    Q.pop();
    if (d[v] == INF){
      d[v] = c;
      for (auto P : E[v]){
        Q.push(make_pair(d[v] + P.first, P.second));
      }
    }
  }
  cout << d[N - 1] << endl;
}
