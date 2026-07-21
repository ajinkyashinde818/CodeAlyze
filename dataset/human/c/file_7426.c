#include <stdio.h>

int main(int argc, char** argv)
{
	int i, max, num[10010];
	i = 0;
	while (1) {
		scanf("%d", &num[i]);

		if (num[i] == 0) {
			break;
		}
		i++;
	}

	max = i;
	for (i = 0; i < max; i++) {
		printf("Case %d: %d\n", i+1, num[i]);
	}
	return 0;
}
