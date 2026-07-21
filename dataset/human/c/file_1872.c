#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main(void) {
	int N,i;
	int A[25], B[25], C[25],ans=0,temp=50,itizi;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	for (i = 0; i < N; i++) {
		scanf("%d", &B[i]);
	}
	for (i = 0; i < N - 1; i++) {
		scanf("%d", &C[i]);
	}

	
	for (i = 0; i < N; i++) {
		itizi = A[i];
		ans = ans + B[itizi-1];
		if (A[i] == temp + 1) {
			ans = ans + C[temp-1];
		}
		temp = A[i];
	}
	printf("%d", ans);
}
