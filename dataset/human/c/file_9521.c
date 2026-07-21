#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
typedef long long ll;

int main()
{
	int N, D, X;
	scanf("%d%d%d", &N, &D, &X);
	int A[N];
	for(int i = 0; i < N; i++) scanf("%d", &A[i]);
	int chocolate;
	for (int j = 0; j < N; j++) {
		chocolate++;
		for (int k = 1; k <= D; k++) {
			int day = k * A[j] + 1;
			if (day <= D) chocolate++;
		}
	}
	chocolate += X;
	printf("%d\n", chocolate);
	return 0;
}
