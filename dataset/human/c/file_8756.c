#include <stdio.h>

int main(void)
{
	int n, a[100000], i, p = 1;

	scanf("%d", &n);
	for (i = 0;i < n;i++) {
		scanf("%d", &a[i]);
	}

	for(i = 1;i < n;i++){
		p = a[p-1];
		if (p == 2) {
			printf("%d\n", i);
			break;
		}
	}

	if (p != 2) {
		printf("-1\n");
	}

	return 0;
}
