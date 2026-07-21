#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>

long long int dp[100000 + 10][2];

int main() {
  int N;
  std::cin >> N;

  std::vector<int> A(N);

  for (int i = 0; i < N; i++) {
    std::cin >> A[i];
  }

  for (int i = 0; i < N-1; i++) {
    // A[i]
    // -1 10 -100
  }

  // std::vector<int> AS(N+1);

  // for (int i = 1; i <= N; i++) {
  //   AS[i] += AS[i-1] + A[i-1];
  // }

  // int answer = std::accumulate(A.begin(), A.end(), 0);

  // for (int i = 0; i < N; i++) {
  //   // i <= x < j までの区間を反転する


  // }

  dp[0][0] = A[0];
  dp[0][1] = -A[0];

  for (int i = 1; i < N; i++) {
    dp[i][0] = std::max(dp[i][0], std::max(dp[i-1][0] + A[i], dp[i-1][1] - A[i]));
    dp[i][1] = std::max(dp[i][1], std::max(dp[i-1][1] + A[i], dp[i-1][0] - A[i]));
  }

  std::cout << dp[N-1][0] << std::endl;
}

// dp[i][s] = i番目をs(1 or -1)倍したときの最大値
