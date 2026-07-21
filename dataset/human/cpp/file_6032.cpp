#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
long long a[100005][2],cnt1[100005],cnt2[100005];
int main()
{
    long long n,c,i,j,l,ans,sum;
    scanf("%lld%lld",&n,&c);
    for(i=0;i<n;i++)
        scanf("%lld%lld",&a[i][0],&a[i][1]);
    ans=0;
    sum=0;
    memset(cnt1,0,sizeof(cnt1));
    memset(cnt2,0,sizeof(cnt2));
    for(i=0;i<n;i++)
    {
        sum+=a[i][1]-a[i][0];
        if(i!=0) cnt1[i]=max(cnt1[i-1],sum);
        else cnt1[0]=sum;
        sum+=a[i][0];
    }
    sum=0;
    for(i=0;i<n;i++)
    {
        sum+=a[n-1-i][1]-c+a[n-1-i][0];
        if(i!=0) cnt2[i]=max(cnt2[i-1],sum);
        else cnt2[0]=sum;
        sum+=c-a[n-1-i][0];
    }
    ans=max(ans,cnt1[n-1]);
    ans=max(ans,cnt2[n-1]);
    sum=0;
    for(i=0;i<n-1;i++)
    {
        sum+=cnt2[n-i-2];
        sum+=a[i][1]-2*a[i][0];
        ans=max(ans,sum);
        sum+=2*a[i][0];
        sum-=cnt2[n-i-2];
    }
    sum=0;
    for(i=0;i<n-1;i++)
    {
        sum+=cnt1[n-i-2];
        sum+=a[n-1-i][1]-2*c+2*a[n-1-i][0];
        ans=max(ans,sum);
        sum+=2*c-2*a[n-1-i][0];
        sum-=cnt1[n-i-2];
    }
    printf("%lld\n",ans);
    return 0;
}
