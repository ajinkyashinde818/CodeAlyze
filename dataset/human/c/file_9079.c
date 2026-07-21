#include <stdio.h>

int main(void) {
	int N;
	int K;
	int i,count=0;
	scanf("%d %d",&N, &K);
	int h[N];
	for(i=0;i<N;i++){
		scanf("%d",&h[i]);
	}
	for(i=0;i<N;i++){
		if(h[i]>=K){
			count=count+1;
		}
	}
	printf("%d",count);
	return 0;
}
