#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<numeric>
#include<utility>
#include<complex>
#include<functional>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
const int INF = (1 << 28);
int n;
ll a[100000];
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i=0;i<n;i++) cin>>a[i];
    ll dp[n][2];
    dp[0][0]=a[0];
    dp[0][1]=-a[0];
    for(int i=1;i<n;i++){
        dp[i][0]=max(dp[i-1][0]+a[i],dp[i-1][1]-a[i]);
        dp[i][1]=max(dp[i-1][0]-a[i],dp[i-1][1]+a[i]);
    }

    cout << dp[n-1][0] << "\n";
}
