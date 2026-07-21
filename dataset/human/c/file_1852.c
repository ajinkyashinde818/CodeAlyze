#include<stdio.h>
int main()
{
    int n,a[21],b[22],c[20],i,s=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++)
        scanf("%d",&b[i]);
    for(i=0;i<n-1;i++)
        scanf("%d",&c[i]);
    for(i=0;i<n;i++)
    {
        s+=b[a[i]-1];
        if(i&&a[i]-a[i-1]==1)
            s+=c[a[i-1]-1];
    }
    printf("%d\n",s);
    return 0;
}
