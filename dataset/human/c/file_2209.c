#include <stdio.h>
#include <string.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void)
{
    char s[100001], c[5];
    int q, t, f;
    scanf("%s%d", s, &q);

    int sCnt = strlen(s), headCnt = 0, tailCnt = 0, rev = 0;
    char head[200001], tail[200001];
    rep(i, q)
    {
        scanf("%d", &t);
        if (t == 1)
            if (rev)
                rev = 0;
            else
                rev = 1;
        else
        {
            scanf("%d%s", &f, c);
            if ((rev == 0 && f == 1) || (rev == 1 && f == 2))
            {
                head[headCnt] = c[0];
                head[headCnt + 1] = '\0';
                headCnt++;
            }
            else if ((rev == 0 && f == 2) || (rev == 1 && f == 1))
            {
                tail[tailCnt] = c[0];
                tail[tailCnt + 1] = '\0';
                tailCnt++;
            }
        }
    }

    if (rev)
    {
        for (int i = tailCnt; i > 0; i--)
            putchar((unsigned char)tail[i - 1]);
        for (int i = sCnt; i > 0; i--)
            putchar((unsigned char)s[i - 1]);
        puts(head);
    }
    else
    {
        for (int i = headCnt; i > 0; i--)
            putchar((unsigned char)head[i - 1]);
        printf("%s", s);
        puts(tail);
    }
    return 0;
}
