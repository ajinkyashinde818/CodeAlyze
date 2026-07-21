#include<stdio.h>
int main()
{
    long long int n;
    while(scanf("%d",&n)==1)
    {
        long long int a[200000],i,low,temp;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
            if(i)
            {
                a[i]+=a[i-1];
            }
        }
        for(i=0;i<n-1;i++)
        {
            if(!(i))
            {
                low=(a[n-1]-a[i])-a[i];
                if(low<1)low=low*(-1);
            }
            else
            {
                temp=(a[n-1]-a[i])-a[i];
                if(temp<1)temp=temp*(-1);
                if(temp<low)low=temp;
            }
        }
        printf("%lld\n",low);
    }
    return 0;
}
