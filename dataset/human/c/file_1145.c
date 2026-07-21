#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int syozyun(const void* x, const void* y) {
	char a = *(const char*)x, b = *(const char*)y;
	return a < b ? -1 : a > b;
}

int kozyun(const void* x, const void* y) {
	char a = *(const char*)x, b = *(const char*)y;
	return a > b ? -1 : a < b;
}

int main(void) {
	char s[128], t[128];
	if (scanf("%127s", s) != 1) return 1;
	if (scanf("%127s", t) != 1) return 1;
	qsort(s, strlen(s), sizeof(*s), syozyun);
	qsort(t, strlen(t), sizeof(*t), kozyun);
	puts(strcmp(s, t) < 0 ? "Yes" : "No");
	return 0;
}
