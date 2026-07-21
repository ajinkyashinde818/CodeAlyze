#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
const ll INF=1e18;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    ll dp[n+1][2];
    for(int i=0;i<n;i++){
        dp[i][0]=-INF;
        dp[i][1]=-INF;
    }
    dp[0][0]=0;
    for(int i=0;i<n;i++){
        dp[i+1][0]=max(dp[i][0]+a[i],dp[i][1]-a[i]);
        dp[i+1][1]=max(dp[i][0]-a[i],dp[i][1]+a[i]);
    }
    cout << dp[n][0] << endl;
}
