#include <iostream>
#include <cstring>
using namespace std;

int main () {
  int coin[3], n;
  cin >> coin[0] >> coin[1] >> coin[2] >> n;
  
  int dp[10000];
  memset(dp, sizeof(dp), 0);
  dp[0] = 1;
  
  for (int i = 0; i < 3; i++) {
    for (int j = coin[i]; j < 4000; j++) {
      dp[j] += dp[j - coin[i]];
    }
  }
  
  cout << dp[n] << '\n';
  return 0;
}
