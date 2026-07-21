#include <cstdio>
#include <iostream>
using namespace std;
typedef long long int ll;
ll a[200005];
ll sum1,sum2;
ll hq;
ll mi;
int n;
int main()
{
    while(~scanf("%lld",&n))
    {
        sum1 = 0;
        sum2 = 0;
        for(int i = 0;i<n;i++)
        {
            scanf("%lld",a+i);
            sum2 += a[i];
        }
        for(int i = 0;i<n - 1;i++)
        {
            sum1 += a[i];
            sum2 -= a[i];
            mi = sum1 - sum2;
            if(mi < 0)
            {
                mi = -mi;
            }
            if(i == 0||mi<hq)
            {
                hq = mi;
            }
        }
        printf("%lld\n",hq);
    }
    return 0;
}
