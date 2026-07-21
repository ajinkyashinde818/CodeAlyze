#include<bits/stdc++.h>
using namespace std;

template <class T> T min2(T a,T b){if(a<b) return a;return b;};

typedef long long ll;
ll a[200005];
int main()
{
    int n;
    cin>>n>>a[0];
    for(int i=1;i<n;i++)
    {
        scanf(" %lld",a+i);
        a[i]+=a[i-1];
    }
    ll ans=abs(2*a[0]-a[n-1]);
    for(int i=1;i<n-1;i++)
    {
        ans=min(ans,abs(2*a[i]-a[n-1]));
    }
    cout<<ans<<endl;
    return 0;
}
