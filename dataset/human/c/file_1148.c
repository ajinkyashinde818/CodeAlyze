#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmpintU(const void *a, const void *b) { return *(char *)a - *(char *)b; }
int cmpintD(const void *a, const void *b) { return *(char *)b - *(char *)a; }
int main() {
	char s[101], t[101];
	scanf("%s%s", s, t);
	qsort(s, strlen(s), sizeof(char), cmpintU);
	qsort(t, strlen(t), sizeof(char), cmpintD);
	if (strcmp(s, t) < 0) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	return 0;
}
