#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>

int main(void) {
	int n;
	int a;
	long long ans = 0;
	int flag = 0;
	int min = INT_MAX,temp;
	int fu_cnt = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		if (a < 0)fu_cnt++;
		else if (a == 0)flag = 1;
		temp = abs(a);
		if (min > temp)min = temp;
		ans += temp;
	}
	if (flag || fu_cnt % 2 == 0)printf("%lld", ans);
	else printf("%lld", ans - 2 * min);
	
	return 0;
}
