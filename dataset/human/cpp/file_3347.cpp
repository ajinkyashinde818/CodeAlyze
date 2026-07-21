#include<iostream>
#include<numeric>
#include<vector>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin>>n;
    vector<ll> a(n);
    vector<vector<ll>> dp(100005,vector<ll>(2));
    dp[0][1]=-1e9;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++){
        dp[i+1][0]=max(dp[i][0]+a[i],dp[i][1]-a[i]);
        dp[i+1][1]=max(dp[i][0]-a[i],dp[i][1]+a[i]);
    }
    cout<<dp[n][0]<<endl;
}
