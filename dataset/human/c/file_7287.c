// AOJ 2665: Hopping Hearts
// 2018.1.3 bal4u@uu


#include <stdio.h>
#include <string.h>

#define M  1000000007

int x[5002], a[5002];
int dp[2][5002];

//#define getchar_unlocked()  getchar()
int in()
{
	int n = 0;
	int c = getchar_unlocked();
	do n = (n<<3)+(n<<1) + (c & 0xf), c = getchar_unlocked();
	while (c >= '0');
	return n;
}

 
int main()
{
    int n, L, i, j, k1, k2;

	n = in(), L = in();
    for (i = 0; i < n; i++) x[i] = in();
    for (i = 0; i < n; i++) a[i] = in();
  
	for (i = 0; i < L; i++) dp[0][i] = 1;
    for (k1 = 0, k2 = 1, i = 0; i < n; i++, k1 = k2, k2 = !k2) {
		memset(dp[k2], 0, sizeof(dp[0]));

		if (!a[i]) {
			if (!(j = x[i])) dp[k2][j] = dp[k1][j];
			else {
				dp[k2][j] += dp[k1][j-1];
				if (dp[k2][j] >= M) dp[k2][j] -= M;
			}
		} else for (j = x[i]; j < L; j += a[i]) {
			if (!j) dp[k2][j] = dp[k1][j];
			else {
				dp[k2][j] += dp[k1][j-1];
				if (dp[k2][j] >= M) dp[k2][j] -= M;
			}
		}
          
		for (j = x[i]; j < L; j++) {
			dp[k2][j+1] += dp[k2][j];
			if (dp[k2][j+1] >= M) dp[k2][j+1] -= M;
		}
    }
    printf("%d\n", dp[k1][L-1]);
    return 0;
}
