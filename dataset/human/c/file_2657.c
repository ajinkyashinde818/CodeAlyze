#include <stdio.h>
int main(void) {
	int N, i, b = 1;
	scanf("%d", &N);
	for (i = 0; b<=N; i++) {
		b = b * 2;
	}
	if (N%b == 0) {
		printf("%d\n",b);
	}
	else {
		b = b / 2;
		printf("%d\n",b);
	}
	return 0;
}
