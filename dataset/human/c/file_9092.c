#include <stdio.h>

int main(void)
{
	int n = 0, k = 0, i = 0, po = 0;
	int human[100001] = { 0 };

	scanf("%d %d", &n, &k);
	for (i = 0; i < n; i++) {
		scanf("%d", &human[i]);
	}

	for (i = 0; i < n; i++) {
		if (human[i] >= k) {
			po++;
		}
	}
	printf("%d", po);

	return 0;
}
