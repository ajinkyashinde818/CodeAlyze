#include <bits/stdc++.h>
using namespace std;
long r,g,b,n;
void solve()
{
    long i,j,k,ans=0,a[3];
    a[0]=r;
    a[1]=g;
    a[2]=b;
    sort(a,a+3);
    for (i=0;i<=n/a[2];i++)
        for (j=0;j<=(n-i*a[2])/a[1];j++)
            if ((n-i*a[2]-j*a[1])%a[0]==0) ans++;
    cout<<ans<<endl;
}
int main()
{
    while(cin>>r>>g>>b>>n)
         solve();
}
