/* Coached by rainboy */
#include <stdio.h>
#include <string.h>

#define N 100000

int main() {
	static char s[N + 1];
	int n, i;

	scanf("%s", s);
	n = strlen(s);
	for (i = 0; i < n; )
		if (s[i] == 'd') {
			if (i + 5 > n || strncmp(s + i, "dream", 5) != 0) {
				printf("NO\n");
				return 0;
			}
			if (i + 7 <= n && strncmp(s + i, "dreamer", 7) == 0 && (i + 7 == n || s[i + 7] != 'a'))
				i += 7;
			else
				i += 5;
		} else if (s[i] == 'e') {
			if (i + 5 > n || strncmp(s + i, "erase", 5) != 0) {
				printf("NO\n");
				return 0;
			}
			if (i + 6 <= n && strncmp(s + i, "eraser", 6) == 0)
				i += 6;
			else
				i += 5;
		} else {
			printf("NO\n");
			return 0;
		}
	printf("YES\n");
	return 0;
}
