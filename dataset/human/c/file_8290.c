#include <stdio.h>

int main(void){
	int N,K;
	scanf("%d",&N);
	char S[N+1];
	scanf("%s",S);
	scanf("%d",&K);

	char e = S[K-1];
	for(int i=0; i<N; i++){
		if(S[i]!=e){ S[i]='*';}
	}

	printf("%s\n",S );
}
