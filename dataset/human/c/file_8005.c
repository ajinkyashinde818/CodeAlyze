#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>

long int calc(long int a, long int b, long int c);

//+1+2 +2+1

int main(void)
{
	long int i, j;
	long int x, y;
	long int a, b, sum;//a:→b↑
	long int min, max;
	long int ans;
	long int warukazu = 1000000007;
	long int work;
	
	scanf("%ld%ld", &x, &y);
	
	if( (x + y) % 3 != 0) {
		printf("0\n");
		return 0;
	}
	
	if( (x > y * 2) || (y > x * 2) ) {
		printf("0\n");
		return 0;
	}
	
	a = (2 * x - y) / 3;
	b = (2 * y - x) / 3;
	sum = a + b;
	
	if(a > b) {
		min = b;
		max = a;
	} else {
		min = a;
		max = b;
	}
	
	ans = 1;
	
	for(i = 2; i <= sum; i++) {
		ans *= i;
		ans %= warukazu;
	}
	
	for(i = 2; i <= min; i++) {
		work = calc(i, warukazu - 2, warukazu);
		ans *= work;
		ans %= warukazu;
	}
	
	for(i = 2; i <= max; i++) {
		work = calc(i, warukazu - 2, warukazu);
		ans *= work;
		ans %= warukazu;
	}
	
	
	printf("%ld\n", ans % warukazu);
	
	return 0;
}

long int calc(long int a, long int b, long int c)
{
	long int x;
	
	if(b == 0) {
		return 1;
	} else if(b % 2 == 0) {
		x = calc(a, b / 2, c);
		return (x * x) % c;
	} else {
		return (a * calc(a, b - 1, c)) % c;
	}
}
