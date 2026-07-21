#include <stdio.h>
#include <stdlib.h>

int main()
{
	long long N;
	scanf("%lld", &N);
	
	if (N % 2 == 1) {
		printf("0\n");
		fflush(stdout);
		return 0;
	}
	
	long long ans = 0;
	for (N /= 10; N > 0; N /= 5) ans += N;
	
	printf("%lld\n", ans);
	fflush(stdout);
	return 0;
}
