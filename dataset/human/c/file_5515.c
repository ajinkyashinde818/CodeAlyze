#include <stdio.h>

int prime_sum[100005];
char prime[200000];

int main(void)
{
	int i, j, n, sum = 0;
	
	prime[2] = 0;
	
	for (i = 2; i < 100000; i++){
		if (prime[i] == 0){
			for (j = 2; j * i < 200000; j++){
				prime[i * j] = 1;
			}
		}
	}
	j = 1;
	for (i = 2; i < 200000; i++){
		if (prime[i] == 0){
			sum += i;
			prime_sum[j] = sum;
			j++;
		}
	}
	
	while (1){
		scanf("%d", &n);
		
		if (n == 0) break;
		
		printf("%d\n", prime_sum[n]);
	}
	
	return (0);
}
