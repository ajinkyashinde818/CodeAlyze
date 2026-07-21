#include <bits/stdc++.h>

typedef long long ll;
const int MAX_N = 100000;

int main() {
  int N;
  ll A[MAX_N];

  std::cin >> N;
  for(int i = 0; i < N; ++i) {
    std::cin >> A[i];
  }

  static ll dp[MAX_N][2] = {};
  dp[0][0] = A[0];
  dp[0][1] = - A[0];
  for(int i = 1; i < N; ++i) {
    dp[i][0] = std::max(dp[i - 1][0] + A[i], dp[i - 1][1] - A[i]);
    dp[i][1] = std::max(dp[i - 1][0] - A[i], dp[i - 1][1] + A[i]);
  }

  std::cout << dp[N - 1][0] << std::endl;
}
