#include <stdio.h>
#include <string.h>

char S[100000], s[4][10] = { "dream", "dreamer", "erase", "eraser" };

int hikaku(int n) {
	int i, j, len;

	for (i = 0; i < 4; i++) {
		len = strlen(s[i]);
		for (j = 1; j <= len; j++) {
			if (s[i][len - j] != S[n - j]) break;
		}
		if (j > len) {
			break;
		}
	}

	if (j > len) {
		return n - j + 1;
	}
	else {
		return -1;
	}
}

int main() {
	int len;

	scanf("%s", S);

	len = strlen(S);

	do {
		len = hikaku(len);
	} while (len != -1 && len != 0);

	if (len == 0) {
		printf("YES");
	}
	else {
		printf("NO");
	}

	return 0;
}
