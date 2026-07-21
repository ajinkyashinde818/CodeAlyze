#include <stdio.h>
int main() {
	int n, d, x, a;
	long int ans = 0;
	scanf("%d%d%d", &n, &d, &x);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a);
		ans += (d - 1) / a + 1;
	}
	printf("%d\n", ans + x);
	return 0;
}
