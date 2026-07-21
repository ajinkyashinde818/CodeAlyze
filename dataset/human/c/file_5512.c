#include <stdio.h>
#include <math.h>
#include <string.h>

#define N	(600000)

char isPrime[N];

int makePrime(void)
{
	int i, j;
	int lim;

	memset(isPrime, 0, sizeof(isPrime));

	lim = sqrt(N);
	for (i = 2; i < lim; i++){
		for (j = i * i; j < N; j += i){
			isPrime[j] = 1;
		}
	}
	return (0);
}

int main(void)
{
	int q;
	int sum, i;

	makePrime();
	while (scanf("%d", &q),q){
		sum = 0; 
		for (i = 2; q; i++){
			if (!isPrime[i]){
				q--;
				sum += i;
			}
		}
		printf("%d\n", sum);
	}

	return (0);
}
