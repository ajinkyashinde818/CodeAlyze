//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <queue>
#include <deque>
#include <set>
#include <stack>
#include <time.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;

const ll nmax = 1e9 + 7;
const ll Mod = 998244353;
const double PI = 2 * asin(1);

double Dist(double X1, double Y1, double X2, double Y2){
  double ans = (X1 - X2) * (X1 - X2);
  ans += (Y1 - Y2) * (Y1 - Y2);
  ans = sqrt(ans);
  return ans;
}

int main(){
  double Xs, Ys, Xt, Yt;
  cin >> Xs >> Ys >> Xt >> Yt;

  int N; cin >> N;
  double X[N + 2], Y[N + 2], R[N + 2];
  X[0] = Xs; Y[0] = Ys; R[0] = 0;
  for (int i = 1; i <= N; i++){
    cin >> X[i] >> Y[i] >> R[i];
  }
  X[N + 1] = Xt; Y[N + 1] = Yt; R[N + 1] = 0;

  vector < pair<double, int> > Graph[N + 2];
  for (int i = 0; i < N + 2; i++){
    for (int j = 0; j < N + 2; j++){
      double dist = Dist(X[i], Y[i], X[j], Y[j]);
      dist -= R[i] + R[j];
      if (dist < 0) dist = 0;
      Graph[i].push_back(make_pair(dist, j));
      Graph[j].push_back(make_pair(dist, i));
    }
  }

  vector <double> ans(N + 2);
  vector <bool> visited(N + 2);

  priority_queue <pair<double, int>, vector<pair<double, int> >, greater<pair<double, int> > > que;
  que.push(make_pair(0, 0));

  while (!que.empty()){
    pair <double, int> P = que.top(); que.pop();
    double D = P.first;
    int now = P.second;

    if (visited[now] == true) continue;

    visited[now] = true;
    ans[now] = D;

    for (int i = 0; i < Graph[now].size(); i++){
      int next = Graph[now][i].second;
      double deg = Graph[now][i].first;
      if (visited[next] == true) continue;      

      que.push(make_pair(D + deg, next)); 
    }
  }
  
  cout << setprecision(16) << ans[N + 1] << endl;

  return 0;
}
