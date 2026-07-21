#include<stdio.h>

int main(){
	int N/*人数*/, D/*日数*/, X/*残量*/;
	scanf("%d", &N);
	scanf("%d %d", &D, &X);
	
//	printf("%d %d %d\n", N, D, X);
	
	int A[N], i;
	
	for(i=0; i<N; i++){
//		printf("\ni=%d\n", i);
		scanf("%d", &A[i]);
//		printf("%d  %d\n", i, A[i]);
	}
	
	int B[N];
	for(i=0; i<N; i++){
		int day=1, j=0;
		do{
			day += A[i];
			j++;
		}while(day<=D);
		B[i] = j;
	}
	
	for(i=0; i<N; i++)	X += B[i];
	
	printf("%d", X);

	return 0;
}
