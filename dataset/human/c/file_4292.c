#include <stdio.h>
#include<stdlib.h>
#define MOD 1000000007
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int *num;
    int now =0;
    num=(int *)malloc((n+1)*sizeof(int));//０段目にnum[0]を用いる
    num[0]=1;
    for (int i = 0; i < m; i++)
    {
        int broken;
        scanf("%d",&broken);
        for (int j = now+1; j < broken; j++)
        {
            if(j==1) num[1]=(broken!=1)*1;
            else num[j]=(num[j-1]+num[j-2])%MOD;
        }
        num[broken]=0;
        now=broken;    
    }
    for (int j = now+1; j <=n; j++)
    {
            if(j==1) num[1]=1;
            else num[j]=(num[j-1]+num[j-2])%MOD;
    }
    printf("%d",num[n]%1000000007);
    free(num);
    return 0;
}
