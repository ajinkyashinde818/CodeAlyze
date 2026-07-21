#include <stdio.h>

int main()
{
	int i, N, D[2], flag = 0;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%d %d", &(D[0]), &(D[1]));
		if (D[0] == D[1]) flag++;
		else flag = 0;
		if (flag == 3) break;
	}
	if (i <= N) printf("Yes\n");
	else printf("No\n");
	fflush(stdout);
	return 0;
}
