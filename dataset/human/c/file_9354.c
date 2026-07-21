#include <stdio.h>

void Syutoku(int N, int* A);
int Sum(int N, int* A, int D);

int main(){

	int N,D,X,ans,A[100] = {0};
	scanf("%d %d %d",&N,&D,&X);
	
	Syutoku(N,&A[0]);
	ans = X + Sum(N,&A[0],D);

	printf("%d",ans);
	
	return 0;
}


void Syutoku(int N, int* A){
	for(int i = 0; i < N; i++){
		scanf("%d",&A[i]);
	}
}

int Sum(int N, int* A, int D){
	int sum = 0;
	for(int i = 0; i < N; i++){
		sum += D / A[i];
		if(D % A[i] != 0) sum++;
	}

	return sum;
}
