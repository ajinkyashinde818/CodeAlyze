#include <stdio.h>
long int n,ans = -20000000,mem;
long int num[200][200] = {0};
int main()
{
    scanf("%ld",&n);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            scanf("%ld",&num[i][j]);
        }
    }
    for(int i = 2; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            num[i][j] = num[i - 1][j] + num[i][j];
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 2; j <= n; j++)
        {
            num[i][j] = num[i][j - 1] + num[i][j];
        }
    }
    for(int i = 0; i <= n - 1; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            for(int k = 0; k <= n - 1; k++)
            {
                for(int l = k + 1; l <= n; l++)
                {
                    mem = num[i][k] - num[i][l] - num[j][k] + num[j][l];
                    if(ans < mem)ans = mem;
                    //printf("%d %d %d %d [%ld]\n",i,j,k,l,mem);
                }
            }
        }
    }
    printf("%ld\n",ans);
    return 0;
}
