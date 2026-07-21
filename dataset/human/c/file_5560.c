#include <stdio.h>

#define SIZE 1000000

int furui[SIZE];
int prime[SIZE];

int main(void) {
	int i, j, k;
	int n;
	long s;

	furui[0] = furui[1] = 1;
	for(i = 2, k = 0; i < SIZE; i++) {
		if(!furui[i]) {
			for(j = i; j < SIZE; j += i) {
				furui[j] = 1;
			}

			prime[k] = i;
			k++;
		}
	}

/*
	if(k > 10000)
		printf("TRUE\n");
	else
		printf("FALSE\n");

	for(i = 0; i < 10; i++) {
		for(j = 0; j < 10; j++) {
			printf("%3d ", prime[i * 10 + j]);
		}

		putchar('\n');
	}
*/

	scanf("%d", &n);
	while(n) {
		for(i = 0, s = 0; i < n; i++) {
			s += prime[i];
		}
		
		printf("%ld\n", s);
		scanf("%d", &n);
	}

	return 0;
}
