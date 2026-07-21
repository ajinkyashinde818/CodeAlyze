#include <stdio.h>

int gcd(int a, int b){
	if(a < b) return gcd(b,a);
	int r = a % b;
	if (r == 0) return b;
	return gcd(r, b);
}

long lcm(int a, int b){
	return (long)a * b / gcd(a,b);
}

int main(void){
	int a,b;
	scanf("%d %d", &a, &b);
	long ans = lcm(a, b);
	printf("%ld", ans);
	return 0;
}
