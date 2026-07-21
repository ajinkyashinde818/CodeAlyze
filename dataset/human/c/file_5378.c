#include<stdio.h>
#include <math.h>

int main(void)
{
	unsigned long int a, b, c;
	unsigned long int i, j, k, l;
	unsigned long int A[12][13];
	unsigned long int B[12];
	unsigned long int sum = 1200001, check, t;
	int tub;

	scanf("%ld%ld%ld", &a, &b, &c);

	for (i = 0; i < a; i++) {
		for (j = 0; j < b + 1; j++) {
			scanf("%ld", &(A[i][j]));
		}
		B[i] = 0;
	}

	for (i = 0; i < (long long int)(pow(2, a)); i++) {
		j = i;
		check = 0;
		for (k = 0; k < b; k++) {
			B[k] = 0;
		}

		for (k = 0; k < a ;k++) {
			if (j % 2 == 1) {
				check = check + A[k][0];
				for (l = 1; l < b + 1; l++) {
					B[l - 1] += A[k][l];
				}
			}
			j = j / 2;
		}
		t = 0;
		for (k = 0; k < b; k++) {
			if (B[k] < c) {
				t = 1;
			}
		}

		if ((t == 0) && (sum > check)) {
			sum = check;
		}
	}



	if (sum == 1200001) {
		printf("-1");
		return 0;
	}

	printf("%lld", sum);

	return 0;
}
