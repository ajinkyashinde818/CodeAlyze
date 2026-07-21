#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
    int n,c,i,j,d,x;
    int p[1000]={0};
    scanf("%d%d%d",&n,&d,&x);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&p[i]);
    }
    for(i=1,c=0;i<=n;i++)
    {
        for(j=0;j*p[i]+1<=d;j++)
        {
            c++;
        }
    }
    c+=x;
    printf("%d\n",c);
    return 0;
}
