#include <stdio.h>

int main()
{
	int k, s;
	int x, y, z;
	long long ans = 0;

	scanf("%d %d", &k, &s);

	for (x = 0; x <= k; x++) {
		for (y = 0; y <= k; y++) {
			z = s - (x + y);

			if (z >= 0 && z <= k) {
				ans++;
			}
		}
	}

	printf("%lld\n", ans);

	return 0;
}
