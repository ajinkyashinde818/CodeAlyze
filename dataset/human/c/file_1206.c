#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int fw(const void *a, const void *b)
{
	return *(char*)a - *(char*)b;
}
int bw(const void *a, const void *b)
{
	return *(char*)b - *(char*)a;
}
int main() {
	char s[111], t[111];
	unsigned int l1, l2;
	scanf("%s%s", s, t);
	l1 = strlen(s);
	l2 = strlen(t);
	qsort(s, l1, sizeof(char), fw);
	qsort(t, l2, sizeof(char), bw);
	for (int i = 0; i <= l1; i++)
	{
		if (s[i] < t[i])
		{
			printf("Yes");
			return 0;
		}
		else if (s[i] == t[i]) {}
		else
		{
			break;
		}
	}
	printf("No");
	return 0;
}
