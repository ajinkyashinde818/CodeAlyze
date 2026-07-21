#include<stdio.h>
int isp[1121];
int prime[500];
int a,b;
int dp[1121][15];
int now;
int main(){
	isp[0]=isp[1]=-1;
	for(int i=2;i<=1120;i++){
		if(isp[i]==0){
			isp[i]=1;
			for(int j=i*2;j<=1120;j+=i)isp[j]=-1;
		}
	}
	for(int i=0;i<1121;i++)if(~isp[i])prime[now++]=i;
	dp[0][0]=1;
	for(int i=0;i<now;i++){
			for(int j=13;j>=0;j--){
		for(int k=0;k<1121;k++){
				if(k+prime[i]<1121)dp[k+prime[i]][j+1]+=dp[k][j];
			}
		}
	}
	while(scanf("%d%d",&a,&b),a+b){
		printf("%d\n",dp[a][b]);
	}
}
