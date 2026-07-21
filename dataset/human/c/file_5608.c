#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define min(a, b) a < b ? a : b
#define max(a, b) a > b ? a : b

int main(void)
{
	long long x, ans;

	scanf("%lld", &x);
	
	if (x % 11 == 0) {
		ans = 2 * (x / 11);
	} else if (x % 11 <= 6){
		ans = 2 * (x / 11) + 1;
	} else {
		ans = 2 * (x / 11) + 2;
	}

	printf("%lld\n", ans);

	return (0);
}
