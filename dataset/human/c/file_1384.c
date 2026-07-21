#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, N, M, a[200001], b[200001];
	scanf("%d %d", &N, &M);
	for (i = 1; i <= M; i++) scanf("%d %d", &(a[i]), &(b[i]));

	int flag[2][200001] = {}, ans = 0;
	for (i = 1; i <= M; i++) {
		if (a[i] == 1) flag[0][b[i]] = 1;
		if (b[i] == 1) flag[0][a[i]] = 1;
		if (a[i] == N) flag[1][b[i]] = 1;
		if (b[i] == N) flag[1][a[i]] = 1;
	}
	for (i = 1; i <= N; i++) if (flag[0][i] & flag[1][i] == 1) ans = 1;
	
	if (ans == 1) printf("POSSIBLE\n");
	else printf("IMPOSSIBLE\n");
	fflush(stdout);
	return 0;
}
