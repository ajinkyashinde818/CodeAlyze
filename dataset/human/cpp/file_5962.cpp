#include <bits/stdc++.h>
using namespace std;
const int N=100000+5;
pair <long long,long long > d[N];
long long n,c,a[N],b[N],x[N],y[N],ma,mb;
int main()
{
    cin >> n >> c;
    for(int i=0;i<n;i++) scanf("%lld %lld",&d[i].first,&d[i].second);
    sort(d,d+n);
    a[0]=d[0].second-d[0].first;
    x[1]=a[0]-d[0].first;
    b[0]=d[n-1].second-(c-d[n-1].first);
    y[1]=b[0]-(c-d[n-1].first);
    ma=a[0],mb=b[0];
    x[0]=y[0]=0;
    for(int i=1;i<n;i++)
    {
        a[i]=a[i-1]+d[i].second-(d[i].first-d[i-1].first);
        x[i+1]=max(x[i],a[i]-d[i].first);
        ma=max(ma,a[i]);
    }
    for(int i=1;i<n;i++)
    {
        b[i]=b[i-1]+d[n-i-1].second-(d[n-i].first-d[n-i-1].first);
        y[i+1]=max(b[i]-(c-d[n-i-1].first),y[i]);
        mb=max(mb,b[i]);
    }
    long long ans=0;
    ans=max(ans,max(ma,mb));
    for(int i=0;i<n;i++) ans=max(ans,a[i]+y[n-i-1]);
    for(int i=0;i<n;i++) ans=max(ans,b[i]+x[n-i-1]);
    printf("%lld\n",ans);
    return 0;
}
