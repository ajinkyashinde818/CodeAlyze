#include<stdio.h>
int main()
{
    int h, w;
    scanf("%d %d", &h, &w);
    char s[55][55];
    int i, j;
    int x;
    for (i = 0; i < h; i++)
        scanf("%s", s[i]);
    for (i = h; i > 0; i--)
        for (j = w; j > 0; j--)
            s[i][j] = s[i - 1][j - 1];
    for (i = 0; i <= h + 1; i++)
        s[i][0] = s[i][w + 1] = '.';
    for (j = 0; j <= w + 1; j++)
        s[0][j] = s[h + 1][j] = '.';
    for (i = 0; i <= h + 1; i++)
    {
        for (j = 0; j <= w + 1; j++)
        {
            x = 1;
            if (s[i][j] == '#')
            {
                x = 0;
                if (s[i][j - 1] == '#')
                    x++;
                if (s[i][j + 1] == '#')
                    x++;
                if (s[i - 1][j] == '#')
                    x++;
                if (s[i + 1][j] == '#')
                    x++;
            }
            if (x == 0)
                break;
        }
        if (x == 0)
            break;
    }
    if (x == 0)
        printf("No\n");
    else
        printf("Yes\n");
    return 0;
}
