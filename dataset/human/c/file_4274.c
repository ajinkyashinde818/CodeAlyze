#include <stdbool.h>
#include <stdio.h>
#define MOD 1000000007
int main() {
	int n, m, a, way[100003] = {0};
	bool isBreak[100003];
	for (int i = 0; i < n; i++) {
		isBreak[i] = false;
	}
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &a);
		isBreak[a] = true;
	}
	way[0] = 1;
	for (int i = 0; i <= n; i++) {
		if (isBreak[i])
			continue;
		way[i + 1] += way[i];
		way[i + 1] %= MOD;
		way[i + 2] += way[i];
		way[i + 2] %= MOD;
	}
	printf("%d\n", way[n]);
	return 0;
}
