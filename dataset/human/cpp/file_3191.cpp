#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
 ll n;
 cin>>n;
 vector<ll> a(n);
 for(ll i=0;i<n;i++) cin>>a[i];
 vector<vector<ll>> dp(n,vector<ll>(2));
 dp[n-1][0]=a[n-1];
 dp[n-1][1]=-a[n-1];
 dp[n-2][0]=max(a[n-1]+a[n-2],-(a[n-1]+a[n-2]));
 dp[n-2][1]=max(-a[n-2]+a[n-1],a[n-2]-a[n-1]);
 for(ll i=n-3;i>=0;i--){
  dp[i][0]=max(a[i]+dp[i+1][0],-a[i]+dp[i+1][1]);
  dp[i][1]=max(-a[i]+dp[i+1][0],a[i]+dp[i+1][1]);
 }
 cout<<dp[0][0]<<endl;
 return 0;
}
