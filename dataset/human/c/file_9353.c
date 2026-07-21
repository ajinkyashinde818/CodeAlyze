#include<stdio.h>

int main() {
	int N, D, X,count=0,countmax=0;
	int A[100];

	scanf("%d", &N);
	scanf("%d %d", &D, &X);

	for (int i = 0; i < N; i++) {

		scanf("%d", &A[i]);
		count =( D-1) / A[i] ;
		countmax += count;
		count = 0;
		
	}

	printf("%d", countmax+X+N);
	return 0;
}
