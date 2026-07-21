#include <stdio.h>

int main(void) {
	int count[3] = {0};
	char S[8];
	int i;
	if (scanf("%7s", S) != 1) return 1;
	for (i = 0; S[i] != '\0'; i++) count[S[i] - 'a']++;
	puts(count[0] == 1 && count[1] == 1 && count[2] == 1 ? "Yes" : "No");
	return 0;
}
