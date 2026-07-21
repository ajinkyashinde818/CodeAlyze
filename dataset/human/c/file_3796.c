#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	long int i, j, k, l, m, n;
	long int a, b;
	long int work, r, x;
	
	scanf("%ld%ld", &a, &b);
	
	if(a < b) {
		work = a;
		a = b;
		b = work;
	}
	
	r = a % b;
	x = a * b;
	
	while(r != 0) {
		a = b;
		b = r;
		r = a % b;
	}
	
	printf("%ld\n", x / b);
	
	return 0;
}
