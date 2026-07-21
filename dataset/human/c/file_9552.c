#include<stdio.h>
int main()
{
    int a[105];
    int n,d,x,i,sum=0;
    scanf("%d %d %d",&n,&d,&x);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        if(d%a[i]==0)
            sum=sum+(d/a[i]);
        else
        sum=sum+(d/a[i]+1);
    }
    sum=sum+x;
    printf("%d",sum);
    return 0;
}
