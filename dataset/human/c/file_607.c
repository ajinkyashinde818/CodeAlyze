#include <stdio.h>

int main()
{
    int n,m,tf = 0;
    int i,j,k,l;
    scanf("%d %d",&n,&m);

    char a[50][51],b[50][51];

    for (i = 0; i < n; i++)
    {
        scanf("%s",a[i]);
    }
    for (i = 0; i < m; i++)
    {
        scanf("%s",b[i]);
    }

    for (i = 0; i <= n - m; i++)
    {
        for (j = 0; j <= n - m; j++)
        {
            for (k = 0; k < m; k++)
            {
                for (l = 0; l < m; l++)
                {
                    if(a[i + k][j + l] != b[k][l])break;
                }
                if(l != m)break;
            }
            if(k == m)tf = 1;
        }
    }
    if(tf == 1){
        printf("Yes");
    }else{
        printf("No");
    }
    
}
