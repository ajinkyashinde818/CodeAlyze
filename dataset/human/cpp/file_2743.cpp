#include<bits/stdc++.h>
using namespace std;

typedef long long lint;

lint dp[100010][2];
int a[100010],n;

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	dp[0][1]=-1e9-1;
	dp[0][0]=0;
	for(int i=0;i<n;i++){
		dp[i+1][0]=max(dp[i][0]+a[i],dp[i][1]-a[i]);
		dp[i+1][1]=max(dp[i][0]-a[i],dp[i][1]+a[i]);
	}
	printf("%lld",dp[n][0]);
	return 0;
}
