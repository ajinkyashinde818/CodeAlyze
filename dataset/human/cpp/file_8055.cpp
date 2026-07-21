#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<string>
#include<bitset>
#include <sstream>
#include<queue>
#include<set>
#include<iomanip>
#include<functional>
#define rep(i,n) for(ll i=0;i<(n);++i)
using namespace std;
typedef long long ll;
typedef pair<ll,ll>P;

const ll INF=1e15;
int main()
{
    int n;
    cin>>n;
    vector<ll> a(n);
    ll sum=0;
    rep(i,n)
    {
        cin>>a[i];
        sum+=a[i];
    }
    ll ans=INF;
    ll pickup=0;
    rep(i,n-1)
    {
        pickup+=a[i];
        ll remainmean=sum-pickup;
        ans=min(ans,abs(remainmean-pickup));

    }
    cout<<ans;

}
