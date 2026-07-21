#include <stdio.h>
#include <math.h>


int main()
{
    int n;
    scanf("%d",&n);
   long long int a[n],ans=100000000000;
    long long int sum=0,ln=0;
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
        sum+=a[i];
    }
    for(int i=0;i<n-1;i++)
    {
        ln+=a[i];
        sum-=a[i];
       long long int k=fabs(sum-ln);
        if(k<ans)
            ans=k;
    }
    printf("%lld",ans);

}
