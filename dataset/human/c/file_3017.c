#include<stdio.h>
#define inf 0x3f3f3f3f
int main()
{
    int k,n,i,sum;
    int a[400400]={};
    while(~scanf("%d%d",&k,&n))
    {
        int minx=inf;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            a[n+i]=a[i];
        }
        for(i=n-1;i<2*n-1;i++)
        {
            if(a[i]>a[i-n+1])
                sum=a[i]-a[i-n+1];
            else
                sum=a[i]+(k-a[i-n+1]);
//            printf("%d %d %d\n",sum,a[i],a[i-n+1]);
            minx=sum>minx?minx:sum;//minx=inf;
        }
        printf("%d\n",minx);
    }
}
