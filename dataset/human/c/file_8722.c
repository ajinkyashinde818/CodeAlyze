#include <stdio.h>
int main() {
	int N;
	scanf("%d", &N);
	int button[N], i;
	for (i = 1; i <= N; i++) {
		int tmp;
		scanf("%d", &tmp);
		button[i] = tmp;
	}
	int now = 1, c = 0;
	for (;;) {
		if (now == 2) {
			printf("%d\n", c);
			break;
		}
		if (c >= N) {
			printf("-1\n");
			break;
		}
		c++;
		now = button[now];
	}
	return 0;
}
