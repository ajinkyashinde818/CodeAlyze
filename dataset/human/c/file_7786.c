#include <stdio.h>

int main(void) {
	int N,i;
	if(scanf("%d",&N)!=1)return 1;
	for(i=0;i<N;i++) {
		int K,P;
		if(scanf("%d%d",&K,&P)!=2)return 1;
		printf("%d\n",(K-1)%P+1);
	}
	return 0;
}
