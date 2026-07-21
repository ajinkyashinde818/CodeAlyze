#include <stdio.h>

int main(void) {
	int n, i, x, maximum;
	int pre[1024], now[1024];
	char in[1024];

	while (1) {
		scanf("%d ", &n);
		if (!n)
			break;

		for (i = 0; i < n+1; i++) {
			pre[i] = now[i] = 0;
		}
		maximum = 0;

		for (i = 0; i < n; i++) {
			scanf("%s ", in);
			for (x = 1; x < n+1; x++) {
				if (in[x-1] == '.') {
					now[x] = pre[x-1] < pre[x] ? pre[x-1] : pre[x];
					now[x] = now[x-1] < now[x] ? now[x-1] : now[x];
					now[x]++;
					if (maximum < now[x]) {
						maximum = now[x];
					}
				}
			}
			for (x = 1; x < n+1; x++) {
				pre[x] = now[x];
				now[x] = 0;
			}
		}
		printf("%d\n", maximum);
	}
	return 0;
}
