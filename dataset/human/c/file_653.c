#include <stdio.h>
#include <string.h>
int main(void)
{
    int n,m,i,j,k,flag=1;
    scanf("%d%d", &n,&m);
    char a[n][n], b[m][m];
    for(i=0; i<n; i++) scanf("%s", &a[i][0]);
    for(i=0; i<m; i++) scanf("%s", &b[i][0]);
    for(i=0; i<=n-m; i++)
    {
        for(j=0; j<=n-m; j++)
        {
            flag=1;
            for(k=0; k<m; k++)
            {
                if(strncmp(&a[i+k][j], &b[k][0], m)!=0)
                {
                    flag=0;
                    break;
                }
            }
            if(flag==1)
            {
                printf("Yes");
                return 0;
            }
        }
    }
    printf("No");
    return 0;
}
