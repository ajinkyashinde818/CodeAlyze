#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
template<typename T1,typename T2> bool chmin(T1 &a,T2 b){if(a<=b)return 0; a=b; return 1;}
template<typename T1,typename T2> bool chmax(T1 &a,T2 b){if(a>=b)return 0; a=b; return 1;}




signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);
 
    ll n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    ll dp[n+1][2]={};

    for(int i=0;i<=n;i++){
        dp[i][0] = -1e18;
        dp[i][1] = -1e18;
    }
    dp[0][0] = 0;
    for(int i=0;i<n-1;i++){
        dp[i+1][0] = max(dp[i][0]+a[i], dp[i][1] - a[i]);
        dp[i+1][1] = max(dp[i][1]+a[i], dp[i][0] - a[i]); 
    }
    dp[n][0] = max(dp[n-1][1]-a[n-1],dp[n-1][0]+a[n-1]);
    cout << dp[n][0] << endl;
}
