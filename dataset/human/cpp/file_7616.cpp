#include<cstdio>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
using namespace std;
long long a[500005],q[500005],h[500005],j[500005];
int main(void)
{
    int n;
    while(~scanf("%d",&n))
    {
        long long sum=0;
        int i;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
            sum+=a[i];
        }
        long long suma=sum;
        for(i=0;i<n;i++)
        {
            sum-=a[i];
            q[i]=suma-sum;
            h[i]=suma-q[i];
        }
        for(i=0;i<n-1;i++)
            j[i]=fabs(q[i]-h[i]);
        sort(j,j+n-1);
        printf("%lld\n",j[0]);
    }
    return 0;
}
