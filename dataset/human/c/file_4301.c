#include <stdio.h>
#include <stdlib.h>
#define P 1000000007
int n, m, i, a[100010];

int main(void)
{
	long long int dp[100010];
	scanf("%d %d", &n, &m);
	for(i=0; i<n+1; i++){ a[i]=1; }
	for(i=0; i<m; i++){
		int f;
		scanf("%d", &f);
		a[f]=0;
	}
	
	dp[0]=1;
	dp[1]=1*a[1];
	for(i=2; i<=n; i++){
			dp[i]=((dp[i-2]+dp[i-1])*a[i])%P;
	}
	printf("%d", dp[n]%P);
	
	return 0;
}
