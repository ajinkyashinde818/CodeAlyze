#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  vector<vector<long long>> dp(N + 1, vector<long long>(2));
  dp[0][0] = 0;
  dp[0][1] = -1e10;
  for (int i = 1; i < N + 1; i++) {
    dp[i][0] = max(dp[i - 1][0] + A[i - 1], dp[i - 1][1] - A[i - 1]);
    dp[i][1] = max(dp[i - 1][0] - A[i - 1], dp[i - 1][1] + A[i - 1]);
  }

  cout << dp[N][0] << endl;

  return 0;
}
