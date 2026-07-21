#include <stdio.h>

int main(int argc, char const *argv[]) {
	char str[101];
	int n, m;
	int ans;

	fgets(str, 100, stdin);
	sscanf(str, "%d %d\n", &n, &m);

	ans = n - m + 1;

	printf("%d\n", ans);

	return 0;
}
