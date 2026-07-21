#include<stdio.h>

long fibo[100001];
long p;


int main(void) {
	int N, M;
	int i;

	scanf("%d%d", &N, &M);

	fibo[0] = 1;
	fibo[1] = 1;
	for (i = 2;i < 100001;i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
		fibo[i] %= 1000000007;
	}
	
	if (M == 0) {
		printf("%ld", fibo[N]);
		return 0;
	}

	int a[M];

	for (i = 0;i < M;i++) {
		scanf("%d", &a[i]);
	}

	int sa[M + 1];
	sa[0] = a[0];
	sa[M] = N - a[M - 1];

	for (i = 0;i < M - 1;i++) {
		if (a[i + 1] == a[i] + 1) {

			printf("%d", 0);

			return 0;
		}
		else {
			sa[i + 1] = a[i + 1] - a[i] - 1;
		}
	}
	
	p = 1;

	for (i = 0;i < M+1;i++) {
		
			p *= fibo[sa[i] - 1];
			p %= 1000000007;
		
	}

	printf("%ld", p % 1000000007);
	
	return 0;
	
}
