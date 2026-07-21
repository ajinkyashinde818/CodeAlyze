#include <stdio.h>

int main(void)
{
	int prime[110000], i, j, s, sum;
	
	for (i = 0; i < 110000; i++){
		prime[i] = 1;
	}
	
	prime[0] = prime[1] = 0;
	
	for (i = 2; i * i <= 110000; i++){
		if (prime[i] == 1){
			for (j = i * i; j <= 110000; j += i){
				prime[j] = 0;
			}
		}
	}
	
	while (scanf("%d", &s), s != 0){
		sum = 0;
		
		i = 0;
		j = 0;
		while (i < s){
			if (prime[j] == 1){
				sum += j;
				i++;
			}
			j++;
		}
		
		printf("%d\n", sum);
	}
	
	return (0);
}
