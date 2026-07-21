#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

int compare1(const void *a, const void *b) {
	char ca = *(char *) a;
	char cb = *(char *) b;

	return ca - cb;
}

int compare2(const void *a, const void *b) {
	char ca = *(char *) a;
	char cb = *(char *) b;

	return cb - ca;
}

int main() {
	static char s[N + 1], t[N + 1];
	int n, m;

	scanf("%s%s", s, t);
	n = strlen(s);
	m = strlen(t);
	qsort(s, n, sizeof *s, compare1);
	qsort(t, m, sizeof *t, compare2);
	printf(strcmp(s, t) < 0 ? "Yes\n" : "No\n");
	return 0;
}
