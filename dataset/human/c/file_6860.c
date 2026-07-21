#include<stdio.h>
int s[100][100] = { 0 };
int dp[100][100] = { 0 };

int sum(int x1, int y1, int x2, int y2) {
	int sum;
	sum = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];
	return sum;
}

int main(void) {
	int n,max=0,a=0;
	int i,j,k,l;
	scanf("%d",&n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			scanf("%d",&s[i][j]);
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			dp[i][j] = s[i][j];
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) 
			dp[i][j] += dp[i][j - 1];
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n ; j++) 
			dp[i][j] += dp[i - 1][j];
	}

	a = sum(0, 0, 0, 0);
	max = a;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			for (k = i; k < n; k++) {
				for (l = j; l < n; l++) {
					a = sum(i,j,k,l);
					if (max < a)
						max = a;
				}
			}
		}
	}
	printf("%d\n",max);
	return 0;
}
