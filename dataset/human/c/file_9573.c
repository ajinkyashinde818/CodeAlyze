#include<stdio.h>
int main()
{
    int n,d,x,a[110],i,j,s=0,m;
    scanf("%d%d%d",&n,&d,&x);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    s+=x;
    for(i=1;i<=n;i++)
    {
        j=1;m=a[i];
        s++;
        m=a[i]*j+1;
        j++;
        while(m<=d)
        {
            s++;
            m=a[i]*j+1;
            j++;
        }
    }
    printf("%d\n",s);
    return 0;
}
