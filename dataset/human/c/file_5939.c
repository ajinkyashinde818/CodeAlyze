#include <stdio.h>

int main(void) {
	int n, i;
	int minv, maxv, tmp;

	scanf("%d", &n);
	scanf("%d", &minv);
	maxv = -999999999;
	for (i = 1; i < n; ++i) {
		scanf("%d", &tmp);
		maxv = (maxv > (tmp - minv)) ? maxv : (tmp - minv);
		minv = (minv > tmp) ? tmp : minv;
	}
	printf("%d\n", maxv);
	
	return 0;
}
