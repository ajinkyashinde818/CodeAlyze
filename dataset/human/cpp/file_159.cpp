#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
// 入力
int R,G,B,N;
int n=3;

// DPテーブル
int dp[4][3001];
int a[4];


int main() {
  for (int i = 0; i < n; ++i) cin >> a[i];
  cin >> N;

  memset(dp, 0, sizeof(dp));   // 一旦すべて 0 に
  dp[0][0] = 1;                // dp[0][0] だけ 1 に

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= N; ++j) {
      dp[i+1][j] += dp[i][j];
      if (j >= a[i]) (dp[i+1][j] += dp[i+1][j-a[i]]);
    }
  }
  cout << dp[n][N] << endl;
}
