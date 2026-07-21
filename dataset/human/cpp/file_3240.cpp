#include<bits/stdc++.h>
using namespace std;

int n;
int a[100005];
long long dp[100005][2];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;

	for(int i=1;i<=n;i++) cin>>a[i];
	dp[2][0]=a[1]+a[2];
	dp[2][1]=-(a[1]+a[2]);
	for(int i=3;i<=n;i++){
		dp[i][0]=max(dp[i-1][0],dp[i-1][1])+a[i];
		dp[i][1]=max(dp[i-1][0]-2*a[i-1]-a[i],dp[i-1][1]+2*a[i-1]-a[i]);
	}
	cout<<max(dp[n][0],dp[n][1]);

    return 0;
}
