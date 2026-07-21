#include <stdio.h>

int main(void)
{
	int N;
	int D;
	int X;
	int A[100];
	
	int i;
	int j;
	int choco = 0;
	
	scanf("%d", &N);
	scanf("%d %d", &D, &X);
	
	for (i = 0; i < N; i++){
		scanf("%d", &A[i]);
	} 
	
	for (i = 0; i < N; i++){
		for (j = 0; j * A[i] < D; j++){
			choco++;
		}
	}
	
	choco += X;
	
	printf("%d\n", choco);
	
	return (0);
}
