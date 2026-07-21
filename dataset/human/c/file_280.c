#include<stdio.h>

#define max(a,b) ((a)>(b)?(a):(b))

int main(){
	int n,i,j;
	long long a[100000];
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%lld",&a[i]);
	long long dp[100000][2]={0};//0:kaeta,1:kaenakatta
	dp[0][0]=-a[0];
	dp[0][1]=a[0];
	for(i=1;i<n-1;i++){
		dp[i][0]=max(dp[i-1][0]+a[i],dp[i-1][1]-a[i]);
		dp[i][1]=max(dp[i-1][0]-a[i],dp[i-1][1]+a[i]);
	}
	dp[n-1][0]=dp[n-2][0]-a[i];
	dp[n-1][1]=dp[n-2][1]+a[i];
	printf("%lld\n",max(dp[n-1][0],dp[n-1][1]));
	return 0;
}
