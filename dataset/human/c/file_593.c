#include <stdio.h>
int main()
{
    int n, m;
    char a[51][51], b[51][51];
    int i, j, k, l;
    scanf("%d %d",&n,&m);
    for (i = 0; i < n; i++)
        //for (j = 0; j < n; j++)
        {
            {
                scanf("%s", a[i]);
            }
        }
    for (i = 0; i < m; i++)
       //for (j = 0; j < m; j++)
        {
            {
                scanf("%s", b[i]);
            }
        }
        int flag=0;
    for (l = 0; l < n - m + 1; l++)
    {
        for (k = 0; k < n - m + 1; k++)
        {
            flag=0;
            for (i = 0; i < m; i++)
            {
                for (j = 0; j < m; j++)
                {
                    if (b[i][j] != a[l + i][k + j])
                    {
                        flag=1;
                    }
                }
            }
            if(flag==0)
            {
                printf("Yes\n");
                return 0;
            }
        }
    }
    if(flag==1)
    {
        printf("No\n");
    }
}
