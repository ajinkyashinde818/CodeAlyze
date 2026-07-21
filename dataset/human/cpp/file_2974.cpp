#include<cstdio>
#include<cstring>
#include<cmath>
#include<cassert>
#include<iostream>
#include<iomanip>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
#define DEBUG(x) cout<<#x<<"="<<x<<endl
#define DEBUG2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
typedef long long ll;
class Solver{
public:
    static const int MAXN=1e5+10;
    int N;
    ll A[MAXN];
    ll dp[MAXN][2];
    void solve(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        cin>>N;
        for(int u=1;u<=N;u++){
            cin>>A[u];
        }
        dp[1][0]=A[1];
        dp[1][1]=-A[1];
        for(int u=2;u<N;u++){
            dp[u][0]=max(dp[u-1][0]+A[u],dp[u-1][1]-A[u]);
            dp[u][1]=max(dp[u-1][1]+A[u],dp[u-1][0]-A[u]);
        }
        ll ans=max(dp[N-1][0]+A[N],dp[N-1][1]-A[N]);
        cout<<ans;
    }
};
int main()
{
    // freopen("in.txt","r",stdin);
    (new Solver())->solve();
}
