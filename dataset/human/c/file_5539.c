#include <stdio.h>

int main(void){
	
	int i;
	int j;
	int k;
	int n;
	int count;
	int sum;
	static int prime[1000001];
	
	for (i = 1; i <= 1000000; i++){
		if (i == 2){
			prime[i] = 1;
		}
		else if (i != 1){
			k = 0;
			for (j = 2; j * j <= i; j++){
				if (i % j == 0){
					k = 1;
					break;
				}
			}
			if (k == 0){
				prime[i] = 1;
			}
		}
	}
	while (1){
		count = 0;
		sum = 0;
		scanf("%d", &n);
		if (n == 0){
			break;
		}
		i = 0;
		while (count < n){
			if (prime[i] == 1){
				sum += i;
				count++;
			}
			i++;
		}
		printf("%d\n", sum);
	}
	
	return 0;
}
