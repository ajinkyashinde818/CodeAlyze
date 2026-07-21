#include <stdio.h>

int main(){
	int N;
	int K;
	int i;
	char str;
	
	scanf("%d",&N);
	
	char S[N];
	
	scanf("%s",&S);
	
	scanf("%d",&K);
	
	str=S[K-1];
	
	for(i=0;i<N;i++){
		if(S[i]!=str)	S[i]='*';
	}
	
	printf("%s",S);
	
	return 0;
}
