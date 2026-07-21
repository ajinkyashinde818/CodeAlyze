#include <stdio.h>

#define H_MAX 50
#define W_MAX 50


int main()
{
    int h, w;
    char s[H_MAX][W_MAX + 1];
    
    scanf("%d %d", &h, &w);
    for (int i = 0; i < h; i++)
    {
	scanf("%s", &s[i]);
    }
    
    for (int i = 0; i < h; i++)
    {
	for (int j = 0; j < w; j++)
	{
	    if (s[i][j] == '#')
	    {
		if (i > 0) // 上
		{
		    if (s[i - 1][j] == '#')
		    {
			continue;
		    }
		}
		if (j > 0) // 左
		{
		    if (s[i][j - 1] == '#')
		    {
			continue;
		    }
		}
		if ((j - 1) < w) // 右
		{
		    if (s[i][j + 1] == '#')
		    {
			continue;
		    }
		}
		if ((i - 1) < h) // 下
		{
		    if (s[i + 1][j] == '#')
		    {
			continue;
		    }
		}
		printf("No\n");
		return 0;
	    }
	}
    }

    printf("Yes\n");

    return 0;
}
