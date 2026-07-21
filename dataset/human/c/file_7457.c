#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int i, j;
	int *tmp = (int *)malloc(1000000000);

	for (i = 0;;i++) {
		scanf("%d", &tmp[i]);
		if (tmp[i] == 0)
			break;
	}
	for (j = 0; j < i; j++)
		printf("Case %d: %ld\n", j+1, tmp[j]);

	free(tmp);

	return 0;
}
