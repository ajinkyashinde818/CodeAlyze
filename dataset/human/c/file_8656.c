#include <stdio.h>
int main(void)
{
    int n,m,k,b,c,x;
    scanf("%d",&n);
    int a[n];
    for(m=1;m<n+1;m++)
    {
        scanf("%d\n",&a[m]);
    }
    b=1;
    x=0;
    a[0]=0;
    for(k=1;k<n;k++)
    {
        if(b>0 && b!=2)
        {
            c=b;
            b=a[c];
            a[c]=0;
            x++;
        }
    }
    if(b==2)
    {
        printf("%d",x);
    }
    else
    {
        printf("-1");
    }
}
