#include<stdio.h>

typedef long long lld;
lld N, NN, ba[101010], sum;

int main(){
	scanf("%lld", &N), NN=N*(N+1)/2;
	for(int i=0; i<N; i++)scanf("%lld", &ba[i]), sum+=ba[i];
	if(sum % NN)puts("NO");
	else{
		sum /= NN;
		for(int i=0; i<N; i++){
			lld t = ba[i]+sum-ba[(i+1)%N];
			if(t<0 || t%N){puts("NO"); return 0;}
		}
		puts("YES");
	}
	return 0;
}
