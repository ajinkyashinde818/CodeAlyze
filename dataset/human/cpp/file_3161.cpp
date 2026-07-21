#include<iostream>
#include<unordered_map>
#include<bitset>
#include<math.h>
#include<vector>
#include<set>
#include<algorithm>
#include<ctype.h>
#include<unordered_set>
#include<string>
#include<iomanip>
#include<queue>
#include<limits>
#include<map>
#include<stack>
#include<iterator>
#include<cstring>
#include<deque>
#include<chrono>
using namespace std;
#define pi 3.141592653589793238

#define gcd __gcd
#define MOD 1000000007
#define INF 999999999999999999 
#define pb push_back
#define ff first
#define ss second
#define mt make_tuple
#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define f0 get<0>
#define f1 get<1>
#define f2 get<2>
typedef vector<ll> vi;
typedef vector<vi> vvi;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fast;
    ll T = 1, i, j;
    
    
    //cin >> T;
    while (T--) {
        ll n;
        cin >> n;
        vector<ll> v(n);
        for(i = 0; i < n; i++){
            cin >> v[i];
        }   
        vector<vector<ll>> dp(n + 1, vector<ll>(2));
        dp[1][0] = v[0];
        dp[1][1] = -INF;
        for(i = 1; i < n; i++){
            dp[i + 1][0] = max(dp[i][0] + v[i], dp[i][1] + v[i]);
            dp[i + 1][1] = max(dp[i][0] - v[i] - 2 * v[i - 1], dp[i][1] - v[i] + 2 * v[i - 1]);
        }
        cout << max(dp[n][0], dp[n][1]);
    }

    return 0;
}
