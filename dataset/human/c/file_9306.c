#include <stdio.h>

int main(void){
	int N,K;
	scanf("%d %d",&N,&K);
	int i,h[N+1];
	for(i=1;i<N+1;i++){
		scanf("%d",&h[i]);
	}
	int ans = 0;
	for(i=1;i<N+1;i++){
		if(h[i] >= K) ans++;
	}
	printf("%d\n",ans);
	
	return 0;
}
