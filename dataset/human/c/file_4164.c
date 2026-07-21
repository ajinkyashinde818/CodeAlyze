#include<stdio.h>

int gcd(int a, int b);

int main() {
	int a, b, k, i;
	scanf("%d%d%d", &a, &b, &k);
	a = gcd(a, b);
	b = 0;
	for (i = a; i > 0; i--) {
		if (a % i == 0) {
			b++;
		}
		if (b == k) {
			a = i;
			break;
		}
	}
	printf("%d", a);
}

int gcd(int a, int b) {
	return (a % b == 0) ? b :  gcd(b, a % b);
}
