#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define min(a,b) ((a)<(b)?(a):(b))

int main(void) {
	int a, b, c, d;
	scanf("%d %d %d", &a, &b, &c);
	
	d = b;
	d += min(b + 1, c);
	d += min(a, c-min(b + 1,c));
	
	printf("%d\n", d);
	
	return 0;
}
