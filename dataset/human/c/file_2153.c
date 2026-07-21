//Double Factorial
#include <stdio.h>
#include <limits.h>

long long factorial(long long num) {
	if(num % 2 != 0) return 0;

	long long NUM = 0;
	num /= 2;
	while (num) {
		NUM += num / 5;
		num /= 5;
	}
	return NUM;
}

int main(){
	long long num;
	scanf("%llu", &num);
	printf("%llu\n", factorial(num));
}
