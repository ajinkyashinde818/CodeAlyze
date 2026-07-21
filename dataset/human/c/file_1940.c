#include<stdio.h>
int main(void)
{
    int n,a[20],b[20],c[20],i,m,s=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++)
        scanf("%d",&b[i]);
    for(i=0;i<n-1;i++)
        scanf("%d",&c[i]);
    m=n;
    for(i=0;i<n;i++){
        s+=b[a[i]-1];
        if(a[i]-1==m+1)
            s+=c[a[i]-2];
        m=a[i]-1;
    }
    printf("%d\n",s);
    return 0;
}
