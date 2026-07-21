#include <stdio.h>

int main()
{
    int n, m, i, j, k, l, count;
    char a[51][51], b[51][51];
    scanf("%d%d", &n, &m);
    for (i=0; i<n; i++)
    {
        scanf("%s", a[i]);
    }
    for (i=0; i<m; i++)
    {
        scanf("%s", b[i]);
    }
    for (i=0; i<=n-m; i++)
    {
        for (j=0; j<=n-m; j++)
        {
            count = 0;
            for (k=0; k<m; k++)
            {
                for (l=0; l<m; l++)
                {
                    if (b[k][l] == a[k+i][l+j])
                    count ++;

                }
            }
            if (count == m*m) {
                break;
            }
        }
        if (count == m*m) {
            break;
        }
    }
    if (count == m*m) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}
