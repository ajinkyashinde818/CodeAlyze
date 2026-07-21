#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>


int main(void)
{
	long int i, j;
	long int n, k;
	long int sum;
	long int max;
	long int count;
	long int a[100];
	long int b[100];
	long int c[100];
	
	scanf("%ld", &n);
	
	for(i = 0; i < n; i++) {
		scanf("%ld", &a[i]);
	}
	
	for(i = 0; i < n; i++) {
		scanf("%ld", &b[i]);
	}
	
	for(i = 0; i < n - 1; i++) {
		scanf("%ld", &c[i]);
	}
	
	sum = b[n - 1];
	
	for(i = 0; i < n - 1; i++) {
		if(a[i] + 1 == a[i + 1]) {
			sum += c[a[i] - 1];
		}
		sum += b[i];
	}
	
	
	printf("%ld\n", sum);
	
	
	return 0;
}
