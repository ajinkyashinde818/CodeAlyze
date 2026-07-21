#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cstring>
#include <utility>
#include <map>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
ll gcd(ll a,ll b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}

int main()
{
    ll n;
    cin>>n;
    vector<ll> a(n);
    ll cnt=0;
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]<0)
            cnt++;
        ans+=abs(a[i]);
        a[i]=abs(a[i]);
    }
    sort(a.begin(),a.end());
    if(cnt%2!=0)
    {
        ans-=(2*a[0]);
    }
    
    
    cout<<ans<<endl;
    return 0;
}
