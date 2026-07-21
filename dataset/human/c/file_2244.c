// AOJ 0092: Square Searching
// 2017.8.12 bal4u@uu
// 2017.11.1 retry

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dp[1002][1002];
char map[1002][1005];

int main()
{
    int n, r, c, t, ans;
    char buf[10];

    while (fgets(buf, 10, stdin) && *buf != '0') {
		n = atoi(buf);
		for (r = 1; r <= n; r++) fgets(map[r]+1, 1005, stdin);

//		memset(dp, 0, sizeof(dp));
		for (ans = 0, r = 1; r <= n; r++) for (c = 1; c <= n; c++) {
			if (map[r][c] == '*') dp[r][c] = 0;
			else {
				t = dp[r-1][c-1];
				if (t > 0 && dp[r  ][c-1] < t) t = dp[r  ][c-1];
				if (t > 0 && dp[r-1][c  ] < t) t = dp[r-1][c  ];
				dp[r][c] = ++t;
				if (t > ans) ans = t;
			}
        }
        printf("%d\n", ans);
    }
    return 0;
}
