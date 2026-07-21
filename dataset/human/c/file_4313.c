#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define ll long long int
#define lim 100010
#define INF 1e9
#define mod 1000000007
#define MIN(x,y) ((x)<(y)?(x):(y))
#define MAX(x,y) ((x)<(y)?(y):(x))
#define ABS(x) ((x)>0?(x):-(x))

int main(void){
	int n,m;
	scanf("%d%d",&n,&m);
	int a[m];
	int c=0;
	ll dp[100010]={1,1};
	for(int i=0;i<m;i++){
		scanf("%d",&a[i]);
		if(a[i]==1){dp[1]=0;c++;}
	}
	for(int i=2;i<=n;i++){
		if(i==a[c]){
			c++;
			dp[i]=0;
		}else{
			dp[i]=dp[i-1]+dp[i-2];
			dp[i] %= mod;
		}
	}
	printf("%lld",dp[n]);
	return 0;
}
