#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int d;
int p[200];
int dp[1121][15][200];

int sumprime(int n,int k,int last)
{
	int i;
	int c=0;
	if(n==0 && k==0){
		return 1;
	}else if(n==0 || k==0){
		return 0;
	}
	if(dp[n][k][last] >= 0)return dp[n][k][last];
	
	for(i=last;i<d;i++){
		if(p[i]>n)break;
		c += sumprime(n-p[i],k-1,i+1);
	}
	
	dp[n][k][last] = c;
	
	return c;
}

int main(void)
{
	int i,j,l,c;
	int n,k;
	
	p[0]=2;
	d = 1;
	for(i=3;i<1121;i+=2){
		c=0;
		for(j=0;j<d;j++){
			if(p[j]*p[j]>i)break;
			if(i%p[j] == 0){
				c++;
				break;
			}
		}
		if(c==0)p[d++]=i;
	}
	
	for(i=0;i<1121;i++){
		for(j=0;j<15;j++){
			for(k=0;k<200;k++){
				dp[i][j][k] = -1;
			}
		}
	}
	
	while(1)
	{
		scanf("%d %d ",&n,&k);
		if(n==0 && k==0)break;
		
		printf("%d\n",sumprime(n,k,0));
	}
	return 0;
}
