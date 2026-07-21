#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;

int main(void){
  int n; cin >> n;
  vector<ll> a(n);
  for(int i=0; i<n; ++i) cin >> a[i];
  ll dp[n][2];
  if( n == 2){
    cout << max( a[0]+a[1], -a[0]-a[1])<<endl;
    return 0;
  }
  dp[0][0] = a[0]; dp[0][1] = -a[0];
  for(int i=1; i<n-1; ++i){
    if( i != n-2){
      dp[i][0] = max(dp[i-1][0] + a[i], dp[i-1][1] - a[i]);
      dp[i][1] = max(dp[i-1][0] - a[i], dp[i-1][1] + a[i]);
    }
    else{
      dp[i][0] = max(dp[i-1][0] + a[i] + a[i+1], dp[i-1][1] - a[i] + a[i+1]);
      dp[i][1] = max(dp[i-1][0] - a[i] - a[i+1], dp[i-1][1] + a[i] - a[i+1]);
    }
  }
  cout << max(dp[n-2][0], dp[n-2][1]) <<endl;
  return 0;
}
