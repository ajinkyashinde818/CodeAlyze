#include <stdio.h>
#include <stdlib.h>
long long b[200001];
int main(void){
	int N;
	scanf("%d",&N);
	long long a[N+1];
	int i;
	b[0]=0;
	for(i=1;i<=N;i++){
		scanf("%lld",&a[i]);
		b[i] = b[i-1]+a[i];
	}
	long long x = b[1];
	long long y = b[N]-b[1];
	long long min = labs(x-y);
	for(i=1;i<N;i++){
		 x = b[i];
		 y = b[N]-b[i];
		if(min>labs(x-y)){
			min = labs(x-y);
		}
	}
	printf("%lld",min);
	return 0;
}
