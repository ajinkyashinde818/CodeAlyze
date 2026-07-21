#include<stdio.h>

int main()
{
	int i,j,h, w, flag;
	char s[101][102];

	scanf("%d%d", &h, &w);

	for (i = 0; i < h; i++)
		scanf("%s", s[i]);

	flag = 1;

	for (i = 0; i < h; i++)
	{
		for (j = 0; j < w; j++)
		{
			if (s[i][j] == '#'&&s[i - 1][j]!='#' && s[i + 1][j] != '#'&&s[i][j - 1] != '#'&&s[i][j + 1] != '#')
			{
				flag = 0;
				break;
			}
		}
	}

	if (flag == 1)
		printf("Yes\n");
	else
		printf("No\n");

	return 0;
}
