#include <stdio.h>
#include <stdlib.h>

int main(){
	int N, D, X, A, i;
	scanf("%d%d%d", &N, &D, &X);
	for(i = 0; i < N; i++){
		scanf("%d", &A);
		X += (D + A - 1) / A;
	}
	printf("%d\n", X);
	return 0;
}
