#include <stdio.h>

int
main(void)
{
	int i;
	int num;
	int idx = 0;
	int input_num[10000];

	while (1) {
		scanf("%d", &num);
		if (num == 0) break;
		input_num[idx] = num;
		idx++;
	}
	for (i = 1; i < idx + 1; i++) {
		printf("Case %d: %d\n", i, input_num[i-1]);
	}

	return 0;
}
