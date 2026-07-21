#include <stdio.h>
#include <math.h>

void hikaku(int *number, int total);

int main(void){
	int N, A[20], B[20], C[20], i, ans=0, D[19], k=0;
	scanf("%d", &N);
	for(i = 0; i < N; i++){
		scanf("%d,", &A[i]);
		if(i > 0){
			if(A[i] == (A[i-1] + 1)){
				D[k] = A[i-1] - 1;
				k++;
			}
		}
	}
	hikaku(D, k);
	k=0;
	for(i=0; i < N; i++){
		scanf("%d,", &B[i]);
		ans += B[i];
	}
	for(i=0; i < N-1; i++){
		scanf("%d,", &C[i]);
		if(D[k] == i){
			ans += C[i];
			k++;
		}
	}
	printf("%d", ans);
    return 0;
}

void hikaku(int *number, int total){
	int i, j, tmp;
	for (i=0; i<total; ++i) {
		for (j=i+1; j<total; ++j) {
			if (number[i] > number[j]) {
				tmp =  number[i];
				number[i] = number[j];
				number[j] = tmp;
			}
		}
	}
}
