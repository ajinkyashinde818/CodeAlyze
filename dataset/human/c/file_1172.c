#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int greater_cmp(const void *x, const void *y);

int main()
{
	char s[105];
	char t[105];

	scanf("%s", s);
	scanf("%s", t);

	qsort(s, strlen(s), sizeof(char), (int (*)(const void *, const void *))strcmp);
	qsort(t, strlen(t), sizeof(char), greater_cmp);

	if (strcmp(s, t) < 0) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}

	return 0;
}

int greater_cmp(const void *x, const void *y)
{
	return -1 * strcmp(x, y);
}
