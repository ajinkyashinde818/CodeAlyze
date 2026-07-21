#include<iostream>
using namespace std;
long long a[100005],dp[100005][2];
int main()
{
	int n,i;
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	
	dp[1][0]=a[1];dp[1][1]=a[1]*-1;
	for(i=2;i<=n;i++){
		dp[i][0]=max(dp[i-1][0]+a[i],dp[i-1][1]-a[i]);
		dp[i][1]=max(dp[i-1][0]-a[i],dp[i-1][1]+a[i]);
	}
	
	cout<<dp[n][0];
	return 0;
 }
