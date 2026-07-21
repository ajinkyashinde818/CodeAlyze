#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int a, b, k;
	scanf("%d%d%d", &a, &b, &k);

	int ans, count;
	if (a >= b) {
		ans = b;
	} else {
		ans = a;
	}
	for (count = 0; ; ans--) {
		if (a % ans == 0 && b % ans == 0) {
			count++;
		}
		if (count == k) {
			break;
		}
	}
	printf("%d\n", ans);
	return 0;
}
