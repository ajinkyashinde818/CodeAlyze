#include <stdio.h>

int main() {
	int i, abc[4] = { 1, 1, 1 };
	char s[4];

	scanf("%s", &s);

	for (i = 0; i < 3; i++) {
		if (s[i] == 'a') abc[0] = 0;
		if (s[i] == 'b') abc[1] = 0;
		if (s[i] == 'c') abc[2] = 0;
	}

	printf(abc[0] + abc[1] + abc[2] == 0 ? "Yes\n" : "No\n");

	return 0;
}
