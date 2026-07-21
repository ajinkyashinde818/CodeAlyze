// Aizu Vol-5 0570: Zig-Zag Numbers
// 2017.9.5 bal4u@uu

#include <stdio.h>
#include <string.h>

#define UP 0
#define DOWN 1
#define M 10000

char a[503], b[503];
int la, lb;
int m;
int dp[2][2][2][10][502];   // prev, org?, up/down, digit, sum %m

int zigzag(char *c, int len)
{
	int i, j, k, s, t, x, k1, k2;

	memset(dp, 0, sizeof(dp));

	if (*c == '0') c++, len--;
	k = *c - '0';
	if (len == 1) for (i = 1; i <= k; i++) dp[0][0][UP][i][i % m] = 1;
	else {
		for (i = 1; i < k; i++) dp[0][0][UP][i][i % m] = dp[0][0][DOWN][i][i % m] = 1;
		dp[0][1][UP][k][k % m] = dp[0][1][DOWN][k][k % m] = 1;
	}

	for (k1 = 0, k2 = 1, i = 1; i < len; i++, k1 = k2, k2 = !k2) {
		for (s = 0; s < 2; s++) for (t = 0; t < 2; t++) for (j = 0; j < 10; j++) for (k = 0; k < m; k++)
			dp[k2][s][t][j][k] = 0;
		
		for (k = 0; k < m; k++) for (j = 0; j < 10; j++) {
			for (s = j+1; s < 10; s++) {
				x = (10*k + s) % m;
				dp[k2][0][UP][s][x] += dp[k1][0][DOWN][j][k];
				if (s <  c[i] - '0')      dp[k2][0][UP][s][x] += dp[k1][1][DOWN][j][k];
				else if (s == c[i] - '0') dp[k2][1][UP][s][x] += dp[k1][1][DOWN][j][k];
			}
			for (s = j-1; s >= 0; s--) {
				x= (10*k + s) % m;
				dp[k2][0][DOWN][s][x] += dp[k1][0][UP][j][k];
				if (s <  c[i] - '0')      dp[k2][0][DOWN][s][x] += dp[k1][1][UP][j][k];
				else if (s == c[i] - '0') dp[k2][1][DOWN][s][x] += dp[k1][1][UP][j][k];
			}
		}
		for (j = 1; j < 10; j++) {
			dp[k2][0][UP][j][j % m]++;
			if (i < len-1) dp[k2][0][DOWN][j][j % m]++;
		}

		for (s = 0; s < 2; s++) for (t = 0; t < 2; t++) for (j = 0; j < 10; j++) for (k = 0; k < m; k++) 
			dp[k2][s][t][j][k] %= M;
	}
	for (s = 0, j = 0; j < 10; j++) {
		s += dp[k1][0][UP][j][0] + dp[k1][1][UP][j][0] +
			 dp[k1][0][DOWN][j][0] + dp[k1][1][DOWN][j][0];
	}
	return s % M;
}

int main()
{
	int i, t;

	scanf("%s%s%d", a, b, &m); la = strlen(a), lb = strlen(b);
	for (i = la-1; ; i--) {
		if (a[i] > '0') { a[i]--; break; }
		a[i] = '9';
	}
	t = zigzag(b, lb);
	if (!(la == 1 && *a == '0')) t -= zigzag(a, la);
	if (t < 0) t += M;
	printf("%d\n", t);
	return 0;
}
