#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    long long int n,i,ans=0,minus=0,min,minnum;
    scanf("%lld", &n);
    long long int a[n];
    for(i=0; i<n; i++) scanf("%lld", &a[i]);
    for(i=0; i<n; i++) if(a[i]<0) minus++;
    if(minus%2==0)
    {
        for(i=0; i<n; i++) ans+=llabs(a[i]);
        printf("%lld", ans);
        return 0;
    } 
    else
    {
        min=llabs(a[0]);
        minnum=0;
        for(i=1; i<n; i++)
        {
            if(llabs(a[i])<min)
            {
                min=llabs(a[i]);
                minnum=i;
            } 
        }
        for(i=0; i<n; i++)
        {
            if(i==minnum) ans-=llabs(a[i]);
            else ans+=llabs(a[i]);
        }
        printf("%lld", ans);
        return 0;
    }
}
