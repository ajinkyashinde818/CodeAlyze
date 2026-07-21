#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
long long a[200010],b[200010];
int main()
{
    int n,m,i,j,k1,k2;
    long long sum,s1,s2,s;
    scanf("%d",&n);
    b[0]=0;
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        b[i]=b[i-1]+a[i];
    }
    s=100000000000000000;
    for(i=1;i<n;i++)
    {
        s1=b[i];
        s2=b[n]-b[i];
        sum=fabs(s1-s2);
        s=min(s,sum);
    }
    printf("%lld\n",s);
    return 0;
}
