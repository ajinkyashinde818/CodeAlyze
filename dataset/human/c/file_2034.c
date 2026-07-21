#include<stdio.h>

int main() {
	long long int a, b, c; 
	scanf("%lld%lld%lld", &a, &b, &c);
	long long int sum = b;
	if(c <= a + b + 1) sum += c;
	if(c > a + b + 1) sum += a + b + 1;
	printf("%lld", sum);
	
	return 0;
}
