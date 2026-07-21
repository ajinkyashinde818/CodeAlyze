// AOJ 1002: Extraordinary Girl I
// 2018.1.18 bal4u

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 0x30303030
int cost[3][3][2][2] = {
	{{{0,3},{1,3}},{{1,2},{1,2}},{{2,2},{2,2}}},
	{{{1,2},{1,2}},{{0,1},{1,2}},{{1,1},{2,2}}},
	{{{2,2},{2,2}},{{1,1},{2,2}},{{0,1},{3,3}}}};
int dp[3][10011];
char shelf[2][10011];
char book[40003];

int main()
{
	int cno, n, n2, i, j, x;
	char buf[10], *p;

	fgets(buf, 10, stdin), cno = atoi(buf);
	while (cno--) {
		fgets(buf, 10, stdin), n = atoi(buf), n2 = n << 1;
		memset(shelf, 0, sizeof(shelf));
		fgets(p=book, 40003, stdin);
		for (i = 0; i < n2; i++) if (*p++ == 'Y') shelf[0][(i+1)>>1] = 1;
		for (i = 0; i < n2; i++) if (*p++ == 'Y') shelf[1][(i+1)>>1] = 1;

		memset(dp, INF, sizeof(dp));
		dp[0][0] = 0;
		for (i = 0; i <= n; i++) for (j = 0; j < 9; j++) {
			x = dp[j/3][i] + cost[j/3][j%3][shelf[0][i]][shelf[1][i]] + 1;
			if (x < dp[j%3][i+1]) dp[j%3][i+1] = x;
		}
		printf("%d\n",dp[0][n+1] - 1);
	}
	return 0;
}
