#include<bits/stdc++.h>
using namespace std;

long long n,a[100005],dp[1][100005];
int main(){
	cin>>n;
	for (long long i=1;i<=n;i++){
		cin>>a[i];
	}
	dp[0][1]=a[1];
	dp[1][1]=-a[1];
	for (long long i=2;i<=n;i++){
		dp[0][i]=max(dp[0][i-1]+a[i],dp[1][i-1]-a[i]);
		dp[1][i]=max(dp[0][i-1]-a[i],dp[1][i-1]+a[i]);
	}
	cout<<dp[0][n];
	return 0;
}
