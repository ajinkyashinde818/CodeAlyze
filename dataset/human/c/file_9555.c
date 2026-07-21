#include <stdio.h>

int main(void)
{
	int N, D, X, A[100];
	int goukei = 0;

	scanf("%d %d %d", &N, &D, &X);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= D; j+= A[i]) {
			goukei++;
		//	printf("%d %d %d\n", i, j, goukei);
		}
	}
	printf("%d", goukei + X);

	//system("pause");

	return 0;
}
