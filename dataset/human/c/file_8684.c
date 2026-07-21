#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int light[100010]={};
    int num[100010]={};
    int n,i,k;
    while (scanf("%d",&n)!=EOF)
    {
        memset(light,0,sizeof (light));
        memset(num,0,sizeof (num));
        for (i=1;i<=n;i++)
        {
            scanf("%d",&light[i]);
        }
        i=1;
        k=0;
        while (i!=2&&num[i]==0)
        {
            num[i]=1;
            i=light[i];
            k++;
        }
        if (i==2)
            printf("%d\n",k);
        else
            printf("-1\n");
    }
    return 0;
}
