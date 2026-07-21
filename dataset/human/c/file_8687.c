#include<stdio.h>
int main()
{
    int a[100000]={},n,i,x=1,m;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    i=1;
    m=n;
    while(n--)
    {
        x=a[i];
        i=x;
        if(x==2)
            break;
    }
    if(n<=0)
        printf("-1\n");
    else
        printf("%d\n",m-n);
    return 0;
}
