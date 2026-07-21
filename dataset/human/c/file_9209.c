#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	long int i, j;
	long int n, k;
	long int count = 0;;
	long int h[100000];
	
	scanf("%ld%ld", &n, &k);
	
	for(i = 0; i < n; i++) {
		scanf("%ld", &h[i]);
		if(h[i] >= k) {
			count++;
		}
	}
	
	printf("%ld\n", count);
	
	return 0;
}
