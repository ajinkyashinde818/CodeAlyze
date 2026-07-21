#include <stdio.h>
#include <math.h>

int main() {
	long long int N, ans = 0, j = 2;
	scanf("%lld",&N);
	if (N % 2 == 0) {
		for (int i = 0; i <= 26; i++) {
			j = j * 5;
			ans = ans + N / j;
		}
		printf("%lld", ans);
	}
	else {
		printf("0");
	}
	return 0;
}
