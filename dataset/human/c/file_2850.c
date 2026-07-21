#include <stdio.h>

int main()
{
	int K, S;
	scanf("%d %d", &K, &S);
	
	int X, Y, Z;
	long long ans = 0;
	for (X = 0; X <= K; X++) {
		for (Y = X; Y <= K; Y++) {
			Z = S - X - Y;
			if (Z >= Y && Z <= K) {
				ans += 6;
				if (X == Y || Y == Z) ans -= 3;
				if (X == Y && Y == Z) ans -= 2;
			}
		}
	}
	
	printf("%lld\n", ans);
	fflush(stdout);
	return 0;
}
