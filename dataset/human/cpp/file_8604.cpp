#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
char s1[55][55], s2[55][55];
bool check(int x, int y)
{
	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(s1[x + i - 1][y + j - 1] != s2[i][j])
				return 0;
		}
	}
	return 1;
}

int main()
{
	while(scanf("%d %d", &n, &m) != EOF)
	{
		bool flag = 0;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				scanf(" %c", &s1[i][j]);
		for(int i = 1; i <= m; i++)
			for(int j = 1; j <= m; j++)
				scanf(" %c", &s2[i][j]);
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				if(s1[i][j] == s2[1][1])
				{
					if(check(i, j))
					{
						flag = 1;
						i = j = n + 1;
					}
				}
			}
		}
		if(flag) printf("Yes\n");
		else printf("No\n");
		memset(s1, 0, sizeof(s1));
		memset(s2, 0, sizeof(s2));
	}
	return 0;
}
