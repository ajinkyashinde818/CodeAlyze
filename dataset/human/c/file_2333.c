#include <stdio.h>
int main() {
	int n, k, s, cnt = 0;
	scanf("%d%d%d", &n, &k, &s);
	for (int i = 0; i < k; i++) {
		printf("%d ", s);
	}
	for (int i = k; i < n; i++) {
		if (s == 1) {
			printf("%d ", 2);
		} else {
			if (cnt == s - 1) {
				printf("%d ", (int)1e9);
				cnt = 0;
			} else {
				printf("%d ", 1);
			}
			cnt++;
		}
	}
	return 0;
}
