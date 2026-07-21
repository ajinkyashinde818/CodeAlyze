#include <stdio.h>

int K, S;
int ans = 0;

int main(void)
{
	scanf("%d%d", &K, &S);

	for (int X = 0; X <= K; ++X)
	{
		for (int Y = 0; Y <= K; ++Y)
		{
			int Z = S - (X + Y);
			if (Z < 0)
			{
			}
			else if (Z > K)
			{
			}
			else if (X + Y + Z == S)
			{
				++ans;
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}
