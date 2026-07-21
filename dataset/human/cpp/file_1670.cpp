#include "bits/stdc++.h"
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	for(long long i = 1, j; ; ++i)
	{
		j = i * (i + 1) / 2;
		if(n == j)
		{
			printf("Yes\n%d\n", i + 1);
			vector<vector<int>> a(i + 1, vector<int>(i, 0));
			int f = 0, o = 1;
			for(; o <= n; )
			{
				for(int k = f; k < i; ++k)
				{
					a[f][k] = o + k - f;
				}
				for(int k = f + 1; k <= i; ++k)
				{
					a[k][f] = o + k - f - 1;
				}
				o += i - f++;
			}
			for(int k = 0; k <= i; ++k)
			{
				printf("%d ", i);
				for(int m = 0; m < i; ++m)
				{
					printf("%d", a[k][m]);
					if(m != i - 1)
					{
						printf(" ");
					}
				}
				printf("\n");
			}
			break;
		}
		else if(n < j)
		{
			printf("No\n");
			break;
		}
	}
}
