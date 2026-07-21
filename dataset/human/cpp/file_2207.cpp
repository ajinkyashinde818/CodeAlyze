#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int INF=1e9;

int main(){
    int n; cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    ll dp[n][2];
    dp[0][0]=a[0];
    dp[0][1]=-a[0];
    for(int i=1;i<n;i++){
        dp[i][0]=max(dp[i-1][0]+a[i],dp[i-1][1]-a[i]);
        dp[i][1]=max(dp[i-1][0]-a[i],dp[i-1][1]+a[i]);
    }
    cout<<dp[n-1][0]<<endl;
}
