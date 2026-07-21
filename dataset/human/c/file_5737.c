#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	int minv, val;
	scanf("%d %d", &minv, &val);
	int maxv = val - minv;
	minv = (minv < val) ? minv : val;
	for (int i = 2; i < n; i++) {
		scanf("%d", &val);
		maxv = (maxv < val - minv) ? val - minv : maxv;
		minv = (minv < val) ? minv : val;
	}

	printf("%d\n", maxv);
}
