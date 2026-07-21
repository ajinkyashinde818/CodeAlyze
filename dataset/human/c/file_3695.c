#include <stdio.h>

int main() {
	long long int A, B;
	scanf("%lld%lld",&A,&B);
	long long int a = A, b = B, q = 1, c;
	if (a < b) {
		c = a;
		a = b;
		b = c;
	}
	while(q != 0) {
			q = a % b;
			a = b, b = q;
	}
	printf("%lld", A * B / a);
	return 0;
}
