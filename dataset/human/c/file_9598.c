#include<stdio.h>

int main() {
	long long n, d, x,a[100];
	scanf("%lld\n", &n);
	scanf("%lld%lld", &d, &x);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	long long sum = x;
	for (int i = 0; i < n; i++) {
		sum += (d-1)/a[i]+1;
	}
	printf("%d", sum);

	return 0;
}
