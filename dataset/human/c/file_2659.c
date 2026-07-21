#include <stdio.h>

const long long mod = 998244353;
int N,K,H; long long C[4002][4002],G[1001][2002];

void add(long long &a, long long b)
{
	a = (a + b) % mod;
}

int main()
{
	scanf ("%d %d",&K,&N); H = K / 2;

	for (int i=0;i<=N+K;i++){
		C[i][0] = C[i][i] = 1;
		for (int j=1;j<i;j++) C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
	}

	G[0][0] = 1;
	for (int i=1;i<=H;i++){
		for (int j=1;j<=N;j++) G[i][j] = (G[i][j-1] + G[i-1][j-1] * 2) % mod;
		for (int j=0;j<=N;j++) add(G[i][j],G[i-1][j]);
	}

	for (int i=2;i<=K*2;i++){
		int c = 0, h = 0;
		for (int j=1;j<=K;j++){
			int k = i - j;
			if (1 <= k && k <= K){
				if (j < k) c++;
				else if (j == k) h++;
			}
		}

		long long res = 0;
		int g = K - 2 * c - h - 1;
		if (g < 0) add(res,G[c][N]);
		else for (int j=0;j<=N;j++) add(res,G[c][j]*C[N-j+g][g]);

		if (h){
			if (g < 0) add(res,G[c][N-1]);
			else for (int j=0;j<=N-1;j++) add(res,G[c][j]*C[N-1-j+g][g]);
		}

		printf ("%lld\n",res);
	}

	return 0;
}
