#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;cin>>n;
  vector<int> arr(n); for(int i=0;i<n;i++)cin>>arr[i];
  vector<vector<long long int > > dp(n,vector<long long int >(2));
  dp[0][0]=arr[0]+arr[1];
  dp[0][1]=-dp[0][0];
  //cout<<0<<": "<<dp[0][0]<<" "<<dp[0][1]<<endl;
  for(int i=1;i<=n-2;i++)
  {
    dp[i][0]=max(dp[i-1][0]+arr[i+1],dp[i-1][1]+arr[i+1]);
    dp[i][1]=max(dp[i-1][0]-2*arr[i]-arr[i+1],dp[i-1][1]+2*arr[i]-arr[i+1]);
    //cout<<i<<": "<<dp[i][0]<<" "<<dp[i][1]<<endl;
  }
  cout<<max(dp[n-2][0],dp[n-2][1])<<endl;
}
