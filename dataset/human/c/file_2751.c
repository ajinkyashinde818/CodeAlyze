#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	int k, s, i, j ,count=0;

	scanf("%d%d", &k, &s);

	for (i = 0; i <= s && i <= k; i++) {
		for (j = 0; j <= s && j <= k; j++) {
			if (s - i - j <= k&&s-i-j>=0){
				count++;
			}
		}
	}

	printf("%d", count);

	return 0;
}
