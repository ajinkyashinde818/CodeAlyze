#include <stdio.h>
#include <stdlib.h>

int *sort_sub(int *T, int N){
	int *ans = (int *)malloc(sizeof(int) * N);
	if(N == 1){
		ans[0] = T[0];
	}
	else{
		int N1 = N / 2;
		int N2 = (N + 1) / 2;
		int *sub1 = sort_sub(&T[0] , N1);
		int *sub2 = sort_sub(&T[N1], N2);
		int i, j, k;
		for(i = 0, j = 0, k = 0; i < N; i++){
			if((sub1[j] > sub2[k] && j != N1) || (k == N2)){
				ans[i] = sub1[j];
				j++;
			}
			else{
				ans[i] = sub2[k];
				k++;
			}
		}
		free(sub1);
		free(sub2);
	}
	return ans;
}

int *sort(int *T, int N){
	int *ans = sort_sub(T, N);
	free(T);
	return ans;
}

int main(){
	int N, i;
	scanf("%d", &N);
	int *a = (int *)malloc(sizeof(int) * 3 * N);
	for(i = 0; i < 3 * N; i++){
		scanf("%d", &a[i]);
	}
	a = sort(a, 3 * N);
	long long int ans = 0;
	for(i = 0; i < N; i++){
		ans += a[2 * i + 1];
	}
	printf("%lld\n", ans);
	return 0;
}
