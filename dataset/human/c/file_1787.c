#include "stdio.h"

int main()
{
	int N = 0;
	int A[21];
	int B[21];
	int C[21];
	int cnt;
	int sum = 0;


	//printf("料理数\n");
	scanf("%d", &N);
	
	//printf("料理品目\n");
	for (cnt = 0; cnt < N; cnt++) {
		scanf("%d", &A[cnt]);

	}
	//printf("満足度\n");
	
	for (cnt = 0; cnt < N; cnt++) {
		scanf("%d", &B[cnt]);
	}
	//printf("追加満足度\n");
	for (cnt = 0; cnt < N - 1; cnt++) {
		scanf("%d", &C[cnt]);
	}



	for (cnt = 1; cnt <= N; cnt++) {
		sum = sum + B[A[cnt - 1] - 1];
		if (cnt - 1 >= 1) {
			if (A[cnt - 2] == A[cnt - 1] - 1) {
				sum = sum + C[A[cnt - 1] - 2];
			}

		}
		
	}
	printf("%d", sum);
	return 0;

}
