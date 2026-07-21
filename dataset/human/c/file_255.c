#include <stdio.h>
#define ll long long int
ll MIN(ll x,ll y){return x<y?x:y;}
ll MAX(ll x,ll y){return x<y?y:x;}
ll ABS(ll x){return x>0?x:-x;}
int main(void){
	int n;
	scanf("%d",&n);
	ll a;
	ll dp[n+1][2];
	dp[0][0] = 0;
	dp[0][1] = -1e10;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a);
		dp[i][0] = MAX(dp[i-1][0]+a,dp[i-1][1]-a);
		dp[i][1] = MAX(dp[i-1][0]-a,dp[i-1][1]+a);	
	}
	printf("%lld",dp[n][0]);
	return 0;
}
