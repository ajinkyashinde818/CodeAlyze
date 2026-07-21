#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int n, i, ans = 0;
	int A[21] = {0};
	int B[21] = {0};
	int C[21] = {0};

	//データ入手
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &A[i]);
	for(i = 0; i < n; i++)
		scanf("%d", &B[i]);
	for(i = 0; i < n-1; i++)
		scanf("%d", &C[i]);

	//計算
	ans = B[A[0]-1];

	for(i = 1; i < n; i++){
		ans += B[A[i]-1];

		if((A[i]-1) == A[i-1]){
			ans += C[A[i]-2];
		}
	}

	printf("%d", ans);


	return EXIT_SUCCESS;
}
