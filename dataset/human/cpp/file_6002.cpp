#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,c;
ll x[100005],v[100005];
ll a[100005];
ll b[100005];
int main()
{
    while(cin>>n>>c)
    {
       memset(a,0,sizeof(a));
       memset(b,0,sizeof(b));
       for(int i=0;i<n;i++)
       {
           cin>>x[i]>>v[i];
       }
       x[n]=c;
       ll ans=0;
       a[0]=v[0]-x[0];
       for(int i=1;i<n;i++)
       {
           a[i]=a[i-1]+v[i]-(x[i]-x[i-1]);
       }
       for(int i=n-1;i>=0;i--)
       {
           b[i]=b[i+1]+v[i]-(x[i+1]-x[i]);
       }
       for(int i=1;i<n;i++)
       {
           a[i]=max(a[i],a[i-1]);
       }
       for(int i=n-2;i>=0;i--)
       {
           b[i]=max(b[i],b[i+1]);
       }
       for(int i=0;i<n;i++)
       {
           ans=max(ans,a[i]);
           ans=max(ans,b[i]);
           ans=max(ans,a[i]-x[i]+b[i+1]);
           ans=max(ans,b[i]-(c-x[i])+a[i-1]);
       }
       cout<<ans<<endl;
    }
    return 0;
}
