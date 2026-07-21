#include <stdio.h>

int main(void)
{
	int n, k, i, h;
	int count = 0;

	scanf("%d %d", &n, &k);

	for (i = 0; i < n; i++) {
		scanf("%d", &h);
		if (h >= k) {
			count++;//入力された身長がKcm以上ならカウントする
		}
	}

	printf("%d\n", count);

	return 0;
}
