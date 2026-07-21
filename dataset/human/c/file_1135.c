#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int cmp1(const void *a, const void *b) {
    return *(char*)a - *(char*)b;
}
int cmp2(const void *a, const void *b) {
    return - *(char*)a + *(char*)b;
}
int main() {
	char s[100], t[100];
	scanf("%s%s",s,t);
	qsort(s, strlen(s), sizeof(char), cmp1);
	qsort(t, strlen(t), sizeof(char), cmp2);
	printf(strcmp(s,t) < 0 ? "Yes":"No");
	return 0;
}
