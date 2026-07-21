#include <stdio.h>

long gcd(long a, long b) {
	if (a == b)
		return a;
	else if (a > b)
		return (gcd(a - b, b));
	else
		return (gcd(a, b - a));
}

int main(void){
	long a, b, lcm;
	scanf("%ld%ld", &a, &b);

	lcm = a * b / gcd(a, b);

	printf("%ld", lcm);
	return 0;
}
