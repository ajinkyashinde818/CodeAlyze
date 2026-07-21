#include <stdio.h>

int main()
{
    int i,j,h,w;
    char s[52][52];

    for (i = 0; i < 52; i++)
    {
        for (j = 0; j < 52; j++)
        {
            s[i][j] = '.';
        }        
    }

    scanf("%d %d",&h,&w);
    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
        {
            scanf("\n%c",&s[i + 1][j + 1]);
        }
    }

    for (i = 1; i <= h; i++)
    {
        for (j = 1; j <= w; j++)
        {
            if(s[i][j] == '#')
            {
                if(s[i][j] != s[i + 1][j] && s[i][j] != s[i - 1][j] && s[i][j] != s[i][j + 1] &&s[i][j] != s[i][j - 1])break;
            }
        }
        if(j != w + 1)break;
    }
    printf("%s\n",i == h + 1 ? "Yes" : "No");
}
