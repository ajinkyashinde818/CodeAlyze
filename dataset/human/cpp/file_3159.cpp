#include <climits>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  for (int& ai : a) cin >> ai;
  ll dp[N + 1][2];
  for (int i = 0; i < N; i++) {
    dp[i][0] = 0;
    dp[i][1] = 0;
  }
  dp[0][1] = INT_MIN;
  for (int i = 0; i < N; i++) {
    dp[i + 1][0] = max(dp[i][0] + a[i], dp[i][1] - a[i]);
    dp[i + 1][1] = max(dp[i][0] - a[i], dp[i][1] + a[i]);
  }
  cout << dp[N][0] << endl;
  /*   int N;
    cin >> N;
    int minnum = INT_MAX;
    int minus = 0;
    bool iszero = false;
    ll sum = 0;
    for (int i = 0; i < N; i++) {
      int num;
      cin >> num;
      if (num < 0) minus++;
      if (num == 0) iszero = true;
      if (num != 0) minnum = min(abs(num), minnum);
      sum += abs(num);
    }
    if ((minus % 2 == 1) && !iszero)
      cout << sum - minnum << endl;
    else
      cout << sum << endl; */
  return 0;
}
