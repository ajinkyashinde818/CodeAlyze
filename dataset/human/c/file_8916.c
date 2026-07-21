#include<stdio.h>
int main(void)
{
	char str[51][51];
	int i,j, h, w,lot;
	lot = 19;
	scanf("%d %d", &h, &w);
	for (i = 0; i < h; i++)
	{
		scanf("%s", &str[i]);
	}
	for (i = 0; i < h; i++)
	{
		if (i == 0) {
			for (j = 0; j < w; j++)
			{
	            if (str[i][j] == '.'&&i == h - 1 && j == w - 1)
				{
					printf("Yes\n");
					lot = 1;
					break;
				}
				else if (str[i][j] == '.')
				{
					continue;
				}
				
				if (j == 0)
				{
					if ((str[i][j] == '#'&&str[i][j + 1] == '#') || (str[i][j] == '#'&&str[i + 1][j] == '#'));
					else
					{
						lot = 0;
						break;
					}
				}
				else if (j == w - 1)
				{
					if ((str[i][j] == '#'&&str[i + 1][j] == '#') || (str[i][j] == '#'&&str[i][j - 1] == '#'));
					else
					{
						lot = 0;
						break;
					}
				}
				else
				{
					if ((str[i][j] == '#'&&str[i][j + 1] == '#') || (str[i][j] == '#'&&str[i + 1][j] == '#')|| (str[i][j] == '#'&&str[i][j - 1] == '#'));
					else
					{
						lot = 0;
						break;
					}
				}
			}
		}
		else if (i == h - 1)
		{
			for (j = 0; j < w; j++)
			{
				if (str[i][j] == '.'&&i == h - 1 && j == w - 1)
				{
					printf("Yes\n");
					lot = 1;
					break;
				}
				else if (str[i][j] == '.')
				{
					continue;
				}
				if (j == 0)
				{
					if ((str[i][j] == '#'&&str[i][j + 1] == '#') || (str[i][j] == '#'&&str[i - 1][j] == '#'));
					else
					{
						lot = 0;
						break;
					}
				}
				else if (j == w - 1)
				{
					if ((str[i][j] == '#'&&str[i - 1][j] == '#') || (str[i][j] == '#'&&str[i][j - 1] == '#'));
					else
					{
						lot = 0;
						break;
					}
				}
				else
				{
					if ((str[i][j] == '#'&&str[i - 1][j] == '#') || (str[i][j] == '#'&&str[i][j + 1] == '#') || (str[i][j] == '#'&&str[i][j - 1] == '#'));
					else
					{
						lot = 0;
						break;
					}
				}
			}
		}
		else
		{
			for (j = 0; j < w; j++)
			{
				if (str[i][j] == '.'&&i == h - 1 && j == w - 1)
				{
					printf("Yes\n");
					lot = 1;
					break;
				}
				else if (str[i][j] == '.')
				{
					continue;
				}
				if (j == 0)
				{
					if ((str[i][j] == '#'&&str[i][j + 1] == '#') || (str[i][j] == '#'&&str[i - 1][j] == '#') || (str[i][j] == '#'&&str[i + 1][j] == '#'));
					else
					{
						lot = 0;
						break;
					}
				}
				else if (j == w - 1)
				{
					if ((str[i][j] == '#'&&str[i][j - 1] == '#') || (str[i][j] == '#'&&str[i - 1][j] == '#') || (str[i][j] == '#'&&str[i + 1][j] == '#'));
					else
					{
						lot = 0;
						break;
					}
				}
				else
				{
					if ((str[i][j] == '#'&&str[i][j - 1] == '#') || (str[i][j] == '#'&&str[i - 1][j] == '#') || (str[i][j] == '#'&&str[i + 1][j] == '#') || (str[i][j] == '#'&&str[i][j + 1] == '#'));
					else
					{
						lot = 0;
						break;
					}
				}
			}
		}

		if (lot == 0)
		{
			printf("No\n");
			break;
		}
		else if (lot == 1)
		{
			;
		}
		else if (i == h - 1)
		{
			printf("Yes\n");
		}
	}
	return 0;
}
