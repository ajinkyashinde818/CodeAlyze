#include <bits/stdc++.h>
#include <stdio.h>
int n,m,j,k,i;
int cou = 0;
int a[10000],b[10000],c[10000] = {0,1};

int main()
{
    while(1)
    {
        int c[10000] = {0,1};
        scanf("%d %d",&n,&m);
        if(n == 0 && m == 0)break;
        for(i = 0; i < m; i++)
        {
            scanf("%d %d",&a[i],&b[i]);
        }
        for( j = 0; j < m; j++)
        {
            if(a[j] == 1)
            {
                cou++;
                c[b[j]] = 1;
            }
        }
        for(k = 0; k < m; k++)
        {
            if(c[a[k]] == 1 && c[b[k]] == 0)
            {
                cou++;
                c[b[k]] = 2;
            }
            if(c[a[k]] == 0 && c[b[k]] == 1)
            {
                cou++;
                c[a[k]] = 2;
            }
        }
        printf("%d\n",cou);
        cou = 0;
    }
    return 0;

}
