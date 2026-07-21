#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    ll n,ans=0,c=0,i;
    cin>>n;
    vector<ll>a(n);
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]<0)
            c++;
    }
    for(i=0;i<n;i++)
    {
        a[i]=abs(a[i]);
    }
    sort(a.rbegin(),a.rend());
    for(i=0;i<n-1;i++)
        ans+=a[i];
        if(c%2==0)
            ans+=a[n-1];
        else
            ans-=a[n-1];
    cout<<ans;
}
