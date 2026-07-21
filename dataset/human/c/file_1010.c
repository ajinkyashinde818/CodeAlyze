#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_N 100
#define MAX_LEN 100

const char *alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(int argc, const char *argv[]) {
	int n;
	int k[MAX_N];
	char s[MAX_LEN + 1];
	int i;

	while(scanf("%d", &n) == 1 && n) {
		for(i = 0; i < n; ++i) {
			scanf("%d", k + i);
		}

		scanf("%s", s);

		const int len = strlen(s);
		for(i = 0; i < len; ++i) {
			const int index = strchr(alpha, s[i]) - alpha;
			const int next_index = (index - k[i % n] + 52) % 52;
			s[i] = alpha[next_index];
		}

		printf("%s\n", s);
	}

	return EXIT_SUCCESS;
}
