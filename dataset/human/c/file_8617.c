#include <stdio.h>

int N;
int a[114514];

char visited[114514];

int main(void) {
	int i;
	int count = 0;
	int current = 1;
	if (scanf("%d", &N) != 1) return 1;
	for (i = 1; i <= N; i++) {
		if (scanf("%d", &a[i]) != 1) return 1;
	}
	for (;;) {
		if (visited[current]) {
			puts("-1");
			return 0;
		}
		if (current == 2) {
			printf("%d\n", count);
			return 0;
		}
		visited[current] = 1;
		current = a[current];
		count++;
	}
}
