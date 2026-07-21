#include <iostream>
#include <vector>
using namespace std;

long long dp[100010][2];
long long INF = -100000000000000;

long long max(long long a, long long b) {
  return a > b ? a : b;
}

int main() {
  int N;
  cin >> N;
  vector<long long> a(N);
  
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  dp[0][0] = 0;
  dp[0][1] = INF;
  
  for (int i = 0; i < N; i++) {
    dp[i+1][0] = max(dp[i][0]+a[i], dp[i][1]-a[i]);
    dp[i+1][1] = max(dp[i][0]-a[i], dp[i][1]+a[i]);
  }

  cout << dp[N][0] << endl;

  return 0;
}
