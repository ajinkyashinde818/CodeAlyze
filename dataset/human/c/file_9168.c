#include <stdio.h>

int main() {
	int sum, border, i, cnt = 0;
	int h;

	scanf("%d %d", &sum, &border);
	for (i = 0; i < sum; i++) {
		scanf("%d", &h);
		if (border <= h) {
			cnt++;
		}
	}

	printf("%d\n", cnt);

	return 0;
}
