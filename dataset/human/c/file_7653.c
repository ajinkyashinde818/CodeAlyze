#include <stdio.h>

int main(void)
{
	int limit = 10000;
	int x[limit];
	int count;
	for (count = 0; count < limit; count++) {
		scanf("%d", &x[count]);
		if (x[count] == 0) {
			break;
		}
	}
	for (int i = 0; i < count; i++) {
		printf("Case %d: %d\n", i + 1, x[i]);
	}
	return 0;
}
