#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int main(void)
{
	int n = 0, m = 0,flag = 0,check = 0;
	char N[60][60], M[60][60],dummy;
	scanf("%d%d",&n, &m);
	scanf("%c", &dummy);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%c", &N[i][j]);
		}
		scanf("%c", &dummy);
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%c", &M[i][j]);
		}
		scanf("%c", &dummy);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i + m - 1 >= n || j + m - 1 >= n)
			{
				continue;
			}
			
			check = 0;

			for (int y = 0; y < m; y++)
			{
				for (int x = 0; x < m; x++)
				{
					if (N[i + y][j + x] != M[y][x])
					{
						check = 1;
					}
				}
			}
			if (check == 0) { flag = 1; }
		}
	}
	
	if (flag == 1) { printf("Yes"); }
	else { printf("No"); }

	return 0;
}
