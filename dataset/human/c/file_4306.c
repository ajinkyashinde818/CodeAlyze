#include <stdio.h>
int main(){
	int N;
	int M;
	int a;
	scanf("%d",&N);
	scanf("%d",&M);
	int i;
	long long int yuka[100001];
	for(i=0;i<=N;i++){
		yuka[i]=1;
	}
	for(i=1;i<=M;i++){
		scanf("%d",&a);
		yuka[a]=0;
	}
	long long int dp[100001];
	dp[0]=1;
	dp[1]=yuka[1];
	for(i=2;i<=N;i++){
		dp[i]=(dp[i-2]*yuka[i-2]+dp[i-1]*yuka[i-1])%1000000007;
	}
	printf("%lld",dp[N]);
}
