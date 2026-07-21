#include <stdio.h>

long long int abs(long long int a){
	if(a>=0){
		return a;
	}
	return -a;
}

long long int min(long long int a, long long int b){
	if(a>b){
		return b;
	}
	return a;
}

int main(){
	long long int N;
	long long int a[200001];
	long long int b[200001];
	long long int i;
	b[0]=0;
	scanf("%lld",&N);
	for(i=1;i<=N;i++){
		scanf("%lld",&a[i]);
		b[i]=b[i-1]+a[i];
	}
	long long int S;
	S=b[N];
	long long int ans;
	ans=abs(S-2*b[1]);
	for(i=2;i<N;i++){
		ans=min(ans,abs(S-2*b[i]));
	}
	printf("%lld",ans);
}
