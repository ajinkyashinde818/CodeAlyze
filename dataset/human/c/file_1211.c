#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>


int cmp(const void* p, const void* q) {
	return *(char*)p - *(char*)q;
}

int cmp2(const void* p, const void* q) {
	return *(char*)q - *(char*)p;
}

int main(void) {
	char s[110], t[110];

	scanf("%s", s);
	scanf("%s", t);

	qsort(s, strlen(s), sizeof(char), cmp);
	qsort(t, strlen(t), sizeof(char), cmp2);
	if (strcmp(s, t) < 0)printf("Yes");
	else printf("No");
	return 0;
}
