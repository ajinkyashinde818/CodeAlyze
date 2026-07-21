#include<stdio.h>

long long ab(long long x){
	if(x<0)return -x;
	return x;
}

int main(){
	int N;
	long long ans=1000000000000000;
	scanf("%d",&N);
	long long a[N];
	long long sum[N+1];
	sum[0]=0;
	for(int i=0;i<N;i++){
		scanf("%lld",&a[i]);
		sum[i+1]=sum[i]+a[i];
	}
	
	for(int i=1;i<N;i++){
		long long tmp;
		tmp=ab(2*sum[i]-sum[N]);
		if(tmp<ans)ans=tmp;
	}
	printf("%lld\n",ans);
	return 0;
}
