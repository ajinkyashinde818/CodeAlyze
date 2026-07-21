#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[4][3001];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int r, g, b, n;
  cin >> r >> g >> b >> n;
  dp[0][0] = 1;
  for (int i = 0; i <= n; i++)
    for (int j = i; j >= 0; j -= r)
      dp[1][i] += dp[0][j];
  for (int i = 0; i <= n; i++)
    for (int j = i; j >= 0; j -= g)
      dp[2][i] += dp[1][j];
  for (int i = 0; i <= n; i++)
    for (int j = i; j >= 0; j -= b)
      dp[3][i] += dp[2][j];
  cout << dp[3][n] << endl;
}
