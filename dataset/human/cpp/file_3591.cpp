#include <cstdio>
#include <climits>
#include <vector>

int main(void) {
  int N;
  scanf("%d", &N);

  std::vector<long long int> A(N);
  for (int i = 0; i < N; ++i) {
    scanf("%lld", &A[i]);
  }

  std::vector< std::vector<long long int> > dp(N+1, std::vector<long long int>(2));
  dp[0][0] = 0; dp[0][1] = INT_MIN;
  for (int i = 1; i <= N; ++i) {
    dp[i][0] = std::max(dp[i-1][0] + A[i-1], dp[i-1][1] - A[i-1]);
    dp[i][1] = std::max(dp[i-1][0] - A[i-1], dp[i-1][1] + A[i-1]);
  }

  printf("%lld\n", dp[N][0]);

  return 0;
}
