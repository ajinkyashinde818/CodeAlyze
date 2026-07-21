#include<stdio.h>
#define MAXN 200000

long long x[MAXN],val[MAXN],rval[MAXN],shun[MAXN],ni[MAXN],w[MAXN];

long long _max(long long x,long long y){return x>y?x:y;}

int main(){
	
	long long ans=0,A=0;
	long long n,c;
	int i;
	scanf("%lld%lld",&n,&c);
	for(i=1;i<=n;i++){
		scanf("%lld%lld",&x[i],&w[i]);
		val[i]=val[i-1]+w[i];
		shun[i]=_max(val[i]-x[i],shun[i-1]);
	}
	for(i=n;i>=1;i--){
		rval[i]=rval[i+1]+w[i];
		ni[i]=_max(rval[i]-c+x[i],ni[i+1]);
	}
	A=0;
	for(i=n;i>=1;i--){
		A=_max(A,rval[i]-2*(c-x[i])+shun[i-1]);
		A=_max(A,ni[i]);
	}
	
	for(i=1;i<=n;i++){
		A=_max(A,val[i]-2*x[i]+ni[i+1]);
		A=_max(A,shun[i]);
	}
	
	printf("%lld",A);
	return 0;
}
