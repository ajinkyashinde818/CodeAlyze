#include <stdio.h>

#define N 10001
#define P 104730 // No.10000 prime number is 104729

int main(void) {
	int is_prime[P];
	int prime[N];
	int i;
	int j;
	int len;
	int input;
	int output;
	
	for (i = 2;i < P;++i) {
		is_prime[i] = 1;
	}
	// sieve of Eratosthenes
	len = P/2;
	for (i = 2;i < len;++i) {
		if (is_prime[i]) {
			for (j = i*2;j < P;j += i) {
				is_prime[j] = 0;
			}
		}
	}
	for (i = 2,j = 0;i < P && j < N;++i) {
		if (is_prime[i]) {
			prime[++j] = i;
		}
	}
	while (1) {
		scanf("%d",&input);
		if (input == 0) {
			break;
		}
		output = 0;
		for (i = 1;i <= input;++i) {
			output += prime[i];
		}
		printf("%d\n",output);
	}
	return 0;
}
