#include <stdio.h>

int main(){
	int N,K;
	char S[11];
	char s2;
	scanf("%d",&N);
	scanf("%s",S);
	scanf("%d",&K);
	s2 = S[K-1];

	for(int i=0;i<N;i++){
		if(S[i]!=s2){
			S[i] ='*';
		}
		printf("%c",S[i]);
	}

	return 0;
}
