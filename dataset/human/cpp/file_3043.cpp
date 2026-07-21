#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  vector<int> a(N);
  for(int i=0;i<N;i++) cin>>a[i];
  long dp[N][2];
  dp[0][0]=0;
  dp[0][1]=-1234567890;
  for(int i=0;i<N;i++){
    dp[i+1][0]=max(dp[i][0]+a[i],dp[i][1]-a[i]);
    dp[i+1][1]=max(dp[i][0]-a[i],dp[i][1]+a[i]);
  }
  cout<<dp[N][0]<<endl;
}
