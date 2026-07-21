#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3 + 5;
const double INF = 1 / .0;

vector<vector<double>> adjMat(MAXN, vector<double> (MAXN, -1));
vector<double> dp(MAXN, INF);

void dijkstra(int n)
{
  vector<int> sptSet(MAXN, 0);
  dp[0] = 0.;
  for(int i = 0; i <= n; i++)
  {
    int u = 0;
    double mm = INF;
    for(int j = 0; j <= n; j++)
    {
      if(sptSet[j] == 0 && dp[j] < mm)
      {
        mm = dp[j];
        u = j;
      }
    }
    sptSet[u] = 1;
    for(int j = 0; j <= n; j++)
    {
      if(sptSet[j] == 0 && adjMat[u][j] != -1 && dp[u] != INF && dp[u] + adjMat[u][j] < dp[j])
      {
        dp[j] = dp[u] + adjMat[u][j];
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  double xs, ys, xt, yt;
  cin >> xs >> ys >> xt >> yt;
  int n;
  cin >> n;
  vector<pair<double, pair<double, double>>> circ(n + 2);
  circ[0] = {0.0, {xs, ys}};
  circ[n + 1] = {0.0, {xt, yt}};
  for(int i = 1; i <= n; i++)
  {
    cin >> circ[i].second.first >> circ[i].second.second >> circ[i].first;
  }
  for(int i = 0; i <= n + 1; i++)
  {
    adjMat[i][i] = 0.0;
    for(int j = i + 1; j <= n + 1; j++)
    {
      double dis = max(0.0, sqrt((circ[i].second.first - circ[j].second.first) * (circ[i].second.first - circ[j].second.first) + (circ[i].second.second - circ[j].second.second) * (circ[i].second.second - circ[j].second.second)) - (circ[i].first + circ[j].first));
      adjMat[i][j] = dis;
      adjMat[j][i] = dis;
    }
  }
  dijkstra(n + 1);
  cout << setprecision(10) << fixed << dp[n + 1] << endl;
  return 0;
}
