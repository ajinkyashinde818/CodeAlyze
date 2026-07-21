#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	long int i, j;
	long int n, k, s;
	long int work;
	
	scanf("%ld%ld%ld", &n, &k, &s);
	
	if(s < 3) {
		for(i = 0; i < k; i++) {
			printf("%ld ", s);
		}
		for(i = 0; i < n - k; i++) {
			printf("%ld ", s + 1);
		}
	} else {
		for(i = 0; i < k; i++) {
			printf("%ld ", s);
		}
		for(i = 0; i < n - k; i++) {
			printf("%ld ", s - 1);
		}
	}
	
	return 0;
}
