#include <stdio.h>
#define NUM 10000
int main(void)
{
	int num[NUM];
	int i, j;
	for (i = 0; i < NUM; i++){
		scanf("%d", &num[i]);
		if (num[i] == 0)break;
	}

	for (j = 0; j < NUM; j++){
		if (num[j] == '\0')break;
		printf("Case %d: %d\n", j + 1, num[j]);
	}

	return 0;
}
