#include <stdio.h>
#include <string.h>

int main(void) {
	char s[51] = { 0 };
	int len;

	scanf("%s", &s);
	len = strlen(s);

	for (int i = 0; i < len - 8; i++) {
		printf("%c", s[i]);
	}
	printf("\n");

	return 0;
}
