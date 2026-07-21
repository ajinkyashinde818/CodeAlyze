#include <stdio.h>
#include <stdlib.h>
#define int long long

signed main(){
	int N, k, i, j;
	scanf("%lld", &N);
	for(k = 1; (k * (k + 1)) / 2 <= N; k++){
		if((k * (k + 1)) / 2 == N){
			printf("Yes\n");
			printf("%lld\n", k + 1);
			int **A = (int **)malloc(sizeof(int *) * (k + 1));
			for(i = 0; i <= k; i++){
				A[i] = (int *)malloc(sizeof(int) * (N + 1));
				for(j = 0; j <= N; j++){
					A[i][j] = 0;
				}
			}
			for(i = 1; i <= k; i++){
				for(j = 1; j <= i; j++){
//					printf("(i, j) = (%lld, %lld)\n", i, j);
					A[j - 1][(i * (i - 1)) / 2 + j] = 1;
					A[i][(i * (i - 1)) / 2 + j] = 1;
				}
			}
			for(i = 0; i <= k; i++){
				printf("%lld ", k);
				for(j = 1; j <= N; j++){
					if(A[i][j] == 1){
						printf("%lld ", j);
					}
				}
				printf("\n");
			}
			return 0;
		}
	}
	printf("No\n");
	return 0;
}
