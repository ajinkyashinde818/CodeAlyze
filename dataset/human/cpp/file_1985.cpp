#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
const ll INF=1e18;
const ll MOD=998244353;
const double pi=3.1415926;
ll n,a[MAXN],dp[MAXN][2],sum;
void solve()
{
    memset(dp,0,sizeof(dp));
    for(ll i=1;i<n;i++)
    {
        dp[i][0]=dp[i-1][0];
        dp[i][1]=dp[i-1][0]-(2*a[i]+2*a[i+1]);
        if(i>1)
        {
            dp[i][0]=max(dp[i][0],dp[i-1][1]);
            dp[i][1]=max(dp[i][1],dp[i-1][1]-(-2*a[i]+2*a[i+1]));
        }

    }
    printf("%lld\n",sum+max(dp[n-1][0],dp[n-1][1]));
}
int main()
{
//    freopen("c://duipai//data.txt","r",stdin);
//    freopen("c://duipai//wa.txt","w",stdout);

    while(~scanf("%lld",&n))
    {
        sum=0;
//        string str;
//        cin>>str;
//        cout<<str<<endl;
        for(ll i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
            sum+=a[i];
        }
        solve();
    }
}
/*
100
3
1 1
1
4
1 1 1
1 1
1
*/
