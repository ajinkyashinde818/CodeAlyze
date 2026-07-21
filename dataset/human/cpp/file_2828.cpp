#include <iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<cctype>
#include<queue>
#include<deque>
#include<regex>
#include<stack>
#include<stdio.h>
#include<vector>
#include<set>
#include<map>
#include<iomanip>

#define rep(i, n) for(int i=0;i<n;i++)

typedef int long long ll;
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const ll MOD = 1e9 + 7;
static const int MAX = 100;
static const int INF = (1 << 23);

int main() {
    ll n;
    cin>>n;
    vector<ll> a(n);
    ll k=0;

    rep(i,n){cin>>a[i];}
   ll dp[n+1][2];
    dp[0][0]=0;
    dp[0][1]=-INF;
    for(int i=0;i<n;i++){
        dp[i+1][0]=max(dp[i][0]+a[i],dp[i][1]-a[i]);
        dp[i+1][1]=max(dp[i][0]-a[i],dp[i][1]+a[i]);
    }

   // cout<<dp[n][1];
   // cout<<dp[n][0];
    cout<<dp[n][0]<<endl;

    return 0;
}
