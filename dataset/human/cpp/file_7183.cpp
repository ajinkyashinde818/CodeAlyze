#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+5;
ll a[maxn];
int main()
{
    int n;
    scanf("%d",&n);
    ll sum=0;
    for(int i=0;i<n;i++) scanf("%lld",&a[i]),sum+=a[i];
    if(n==2)
    {
        printf("%lld\n",abs(a[0]-a[1]));
        return 0;
    }
    ll ans=0,s=1e18;
    for(int i=0;i<n-1;i++)
    {
        ans+=a[i];
        ll k=sum-ans;
        s=min(s,abs(k-ans));
    }
    printf("%lld\n",s);
}
