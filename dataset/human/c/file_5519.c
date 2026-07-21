#include <stdio.h>
#include <math.h>	//10000番目の素数が104729
#define Max 104730
int main(void)
{

	int i,j,prime[Max]={0},n;
	prime[0]=1;
	prime[1]=1;
	for(i=2;i<sqrt(Max);i++){	//i<=j && i*j<Max⇒i<=sart(Max)
		for(j=2;i*j<Max;j++){
			prime[i*j]=1;		//xが素数⇒prime[x]=0,素数以外⇒prime[x]=1を代入
		}
	}
	while(scanf("%d",&n)){
		if(n==0) break;
		long long sum=0;
		int count=1;
		for(i=0;count<=n;i++){
			if(prime[i]==0){
				sum+=i;
				count++;
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
}
