#include <stdio.h>

#define N 100000

int main() {
	static char used[N];
	static int aa[N];
	int n, k, i;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &aa[i]), aa[i]--;
	k = 0;
	for (i = 0; !used[i] && i != 1; i = aa[i]) {
		used[i] = 1;
		k++;
	}
	printf("%d\n", i == 1 ? k : -1);
	return 0;
}
