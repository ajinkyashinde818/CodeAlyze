#include<bits/stdc++.h>
using namespace std;

const int sz = 3030;
int dp[sz][3];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  memset(dp, 0, sizeof dp);
  int n;
  vector<int> v(3);
  cin>>v[0]>>v[1]>>v[2]>>n;
  dp[0][0] = 1;
  for(int i=0;i<=n;i++) {
    for(int j=0;j<3;j++) {
      if(j) {
        dp[i][j] += dp[i][j-1];
      }
      if(i - v[j] >= 0) {
        dp[i][j] += dp[i-v[j]][j];
      }
    }
  }
  cout<<dp[n][2];
  return 0;
}
