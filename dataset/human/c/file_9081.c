#include<stdio.h>
#include <stdlib.h>
int N, K, h, ans = 0;
int main(){
	scanf("%d%d",&N,&K);
	for(int i=0; i<N; i++){
		scanf("%d",&h);
		ans += (h >= K);
	}
	printf("%d\n",ans);
	return 0;
}
