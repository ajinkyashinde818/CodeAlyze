#include <stdio.h>
#include <stdlib.h>

int main() {
	int k, s;
	int sum;
	int i, j;
	scanf("%d %d", &k, &s);

	sum = 0;
	for (i = 0; i < s + 1; i ++) {
		for (j = i + 1; j < s + 2; j ++) {
			if (i <= k && j - i - 1 <= k && s+1 - j <= k) {
				sum ++;
			}
		}
	}
	printf("%d", sum);
	return 0;
}
