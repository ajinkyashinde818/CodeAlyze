#include <stdio.h>

int main()
{
	int i, D, G, p[11], c[11];
	scanf("%d %d", &D, &G);
	for (i = 1; i <= D; i++) scanf("%d %d", &(p[i]), &(c[i]));
	
	int ans = 1000, rest, count, comp[11] = {};
	while (comp[0] == 0) {
		rest = G / 100;
		count = 0;
		for (i = 1; i <= D; i++) {
			if (comp[i] == 1) {
				count += p[i];
				rest -= p[i] * i + c[i] / 100;
			}
		}
		for (i = D; i >= 1 && rest > 0; i--) {
			if (comp[i] == 1) continue;
			else if (rest > (p[i] - 1) * i) break;
			else {
				count += (rest + i - 1) / i;
				rest = 0;
			}
		}
		if (rest <= 0 && count < ans) ans = count;
		
		for (i = D; i >= 1 && comp[i] == 1; i--);
		for (comp[i++] = 1; i <= D; comp[i++] = 0);
	}
	
	printf("%d\n", ans);
	fflush(stdout);
	return 0;
}
