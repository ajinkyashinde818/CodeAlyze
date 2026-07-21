#include <stdio.h>

int main(void)
{
	int n, di, dy;
	int i, j = 0, count = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d %d", &di, &dy);
		if (di == dy) {
			count++;
			if (count == 3) {
				j++;
				count = 0;
			}
		}
		else {
			count = 0;
		}
	}

	if (j > 0) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}

	return 0;
}
