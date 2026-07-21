#include<stdio.h>

int main(void) {

	int i = 0, n, a[10000];

	while (1) {

		scanf("%d", &a[i]);

			if (a[i] == 0)
				break;

			i++;

	}

	n = i;
	for (i = 0; i < n; i++)

		printf("Case %d: %d\n", i + 1, a[i]);

	return 0;

}
