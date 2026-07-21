#include <stdio.h>

int main(){
	int N;
	if(scanf("%d", &N) == 1);
	int l;
	for(l=1; l<N; l++){
		N -= l;
	}
	if(N != l){
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	printf("%d\n", l+1);
	int answer[l+1][l];
	int Index = 1;
	for(int i=0; i<=l; i++){
		printf("%d", l);
		int j=0;
		for(; j<i; j++){
			printf(" %d", answer[j][i-1]);
		}
		for(; j<l; j++){
			printf(" %d", answer[i][j]=Index++);
		}
		printf("\n");
	}
	return 0;
}
