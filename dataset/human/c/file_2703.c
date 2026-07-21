#include <stdio.h>

int main(void)
{
	int K, S;
	int X, Y, Z;
	int cnt = 0;

	scanf("%d", &K);
	scanf("%d", &S);

	for (X = 0; X <= K; X++) {
		for (Y = 0; Y <= K; Y++) {
			Z = S - X - Y;
			if (0 <= Z && Z <= K)
				cnt++;
		}
	}

	printf("%d", cnt);
	return 0;
}
