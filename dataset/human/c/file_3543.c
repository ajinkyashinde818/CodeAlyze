#include <stdio.h>

int main(void) {
	int N;
	int ACnum[128] = {0};
	int i;
	int ok, ng;
	if (scanf("%d", &N) != 1) return 1;
	for (i = 0; i < N; i++) {
		int p;
		if (scanf("%d", &p) != 1) return 1;
		ACnum[p]++;
	}
	for (i = 100; i > 1; i--) ACnum[i - 1] += ACnum[i];
	ok = 0;
	ng = 101;
	while (ng - ok > 1) {
		int mid = (ng - ok) / 2 + ok;
		if (ACnum[mid] >= mid) ok = mid; else ng = mid;
	}
	printf("%d\n", ok);
	return 0;
}
