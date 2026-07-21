#include <stdio.h>

int main(void)
{
	int N, a[100000][2] = {}, ans = 0, tmp = 0, i;
	scanf("%d", &N);
	for (i = 0; i < N; ++i) scanf("%d", &a[i][0]);
	for (i = 0; a[i][0] != 2; ++ans) {
		if (a[i][1] == 1) {
			tmp = 1;
			break;
		}
		a[i][1] = 1;
		i = a[i][0] - 1;
	}
	if (tmp == 0) printf("%d", ans + 1);
	else puts("-1");
	return 0;
}
