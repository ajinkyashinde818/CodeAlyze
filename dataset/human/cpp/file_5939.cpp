#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
long long a[N],b[N],c[N],d[N],e[N],f[N],m,n;
int main()
{
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        cin>>a[i]>>b[i],c[i]=m-a[i],d[i]=b[i],b[i]+=b[i-1];
    for(int i=n; i>=0; i--)
        d[i]+=d[i+1];
    for(int i=1; i<=n; i++)
        e[i]=max(e[i-1],b[i]-2*a[i]),f[i]=max(f[i-1],b[i]-a[i]);
    long long ans=0;
    for(int i=1; i<=n+1; i++)
        ans=max(ans,max(e[i-1]+d[i]-c[i],f[i-1]+d[i]-2*c[i]));
    cout<<ans;
    return 0;
}
