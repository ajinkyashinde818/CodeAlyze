#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
const int maxn=200000;
long long int a[maxn];
int main()
{
    long long int i,j,n,sum=0,sum1=0,sum2=0,min;
    scanf("%lld",&n);
    long long int c[n-1];
    for(i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
        min+=fabs(a[i]);
        sum+=a[i];
    }
    for(j=n-1;j>0;j--)
    {
        sum1+=a[j];
        if(fabs(2*sum1-sum)<min)
        {
            min=fabs(2*sum1-sum);
        }
    }
    printf("%lld\n",min);
}
