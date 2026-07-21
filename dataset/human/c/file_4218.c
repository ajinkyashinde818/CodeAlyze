#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Mod 1000000007

int main(void){
	long i;
	long long ans=1;
	
	long n,m;
	scanf("%ld%ld",&n,&m);
	
	long a[m+2];
	a[0]=-1;
	a[m+1]=n+1;
	for(i=1;i<=m;i++){
		scanf("%ld",&a[i]);
	}
	
	long d[m+1];
	for(i=0;i<=m;i++){
		d[i]=a[i+1]-a[i]-1;
	}
	
	long fib[n+1];
	fib[0]=0,fib[1]=1,fib[2]=1,fib[3]=2;
	for(i=4;i<=n+1;i++){
		fib[i]=(fib[i-1]+fib[i-2])%Mod;
	}
	
	for(i=0;i<=m;i++){
		ans=(ans*fib[d[i]])%Mod;
	}
	
	printf("%lld\n",ans);
	
	return 0;
}
