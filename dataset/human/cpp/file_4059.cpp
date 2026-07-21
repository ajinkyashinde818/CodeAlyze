#include<bits/stdc++.h>

using namespace std;

const double INF = 4e9;

int main(){
  double xs, ys, xt, yt;
  cin >> xs >> ys >> xt >> yt;
  
  int N;
  cin >> N;
  
  vector<double> x(N + 2), y(N + 2), r(N + 2);
  
  x[0] = xs, y[0] = ys, r[0] = 0;
  x[N + 1] = xt, y[N + 1] = yt, r[N + 1] = 0;
  
  for(int i = 1; i <= N; i++){
    cin >> x[i] >> y[i] >> r[i];
  }
  
  vector<vector<pair<double, int>>> to(N + 2);
  
  for(int i = 0; i <= N + 1; i++){
    for(int j = 0; j <= N + 1; j++){
      double d = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
      d -= r[i] + r[j];
      d = max(d, 0.0);
      
      to[i].push_back(make_pair(d, j));
      to[j].push_back(make_pair(d, i));
    }
  }
  
  vector<double> exposed(N + 2, INF);
  vector<bool> used(N + 2, false);
  priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
  
  exposed[0] = 0;
  pq.push(make_pair(0.0, 0));
  
  while(!pq.empty()){
    auto cur = pq.top();
    pq.pop();
    
    if(used[cur.second]) continue;
    used[cur.second] = true;
    
    for(auto next : to[cur.second]){
      if(cur.first + next.first < exposed[next.second]){
        exposed[next.second] = cur.first + next.first;
        pq.push(make_pair(exposed[next.second], next.second));
      }
    }
  }
  
  cout << fixed << setprecision(10) << exposed[N + 1] << endl;
  
  return 0;
}
