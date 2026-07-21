#include <stdio.h>
#include <stdlib.h>
#define int long long
#define inf (int)(1e18)

int max(int a, int b){
	return a >= b ? a : b;
}

signed main(){
	int N, i, j, k;
	scanf("%lld", &N);
	int **a = (int **)malloc(sizeof(int *) * N);
	for(i = 0; i < N; i++){
		a[i] = (int *)malloc(sizeof(int) * N);
		for(j = 0; j < N; j++){
			scanf("%lld", &a[i][j]);
		}
	}
	int *dp = (int *)malloc(sizeof(int) * (1 << N));
	for(i = 0; i < (1 << N); i++){
		dp[i] = 0;
		for(j = 0; j < N; j++){
			for(k = j + 1; k < N; k++){
				if((i | (1 << j)) == i && (i | (1 << k)) == i){
					dp[i] += a[j][k];
				}
			}
		}
		for(j = ((i - 1) & i); j > 0; j = ((j - 1) & i)){
			dp[i] = max(dp[i], dp[j] + dp[i ^ j]);
		}
	}
	printf("%lld\n", dp[(1 << N) - 1]);
	return 0;
}
