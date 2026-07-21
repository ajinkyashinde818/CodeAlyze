#include<stdio.h>
int main()
{
    int i,j,x[10000];
    for(i=1;i<=10000;i++)
    {
        scanf("%d",&x[i]);
        if(x[i]==0)
            break;
    }
    for(i=1;i<=10000;i++)
    {
        if(x[i]==0)
            break;
        printf("Case %d: %d\n",i,x[i]);
    }
return 0;
}
