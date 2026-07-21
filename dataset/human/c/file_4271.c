#include <stdio.h>

#define MOD_BY 1000000007

int add(int a, int b) {
	return a + b - MOD_BY * (a + b >= MOD_BY);
}

int N, M;
int a[114514];

char dame[114514];

int memo[114514];

int kitaeri(int cur) {
	if (cur == N) return 1;
	if (cur > N) return 0;
	if (dame[cur]) return 0;
	if (memo[cur]) return ~memo[cur];
	return ~(memo[cur] = ~add(kitaeri(cur + 1), kitaeri(cur + 2)));
}

int main(void) {
	int i;
	if (scanf("%d%d", &N, &M) != 2) return 1;
	for (i = 0; i < M; i++) {
		if (scanf("%d", &a[i]) != 1) return 1;
		dame[a[i]] = 1;
	}
	printf("%d\n", kitaeri(0));
	return 0;
}
