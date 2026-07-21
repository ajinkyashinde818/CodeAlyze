#include<stdio.h>
int main(void)
{
    int n,k,a[100005],i,count=0;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]>=k)
            count++;
    }
    printf("%d\n",count);
    return 0;
}
