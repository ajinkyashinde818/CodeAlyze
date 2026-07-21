#include<stdio.h>
#define mod 1000000007

int main(){
	int n,m,i;
	int a[100000];
	long long dp[100101]={1};
	int ss[1000101]={0};
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d",&a[i]);
		ss[a[i]]=1;
	}
	for(i=0;i<=n;i++){
		if(ss[i]!=1){
			dp[i+1]+=dp[i];
			dp[i+1]%=mod;
			dp[i+2]+=dp[i];
			dp[i+2]%=mod;
		}
	}
	printf("%lld\n",dp[n]);
	return 0;
}
