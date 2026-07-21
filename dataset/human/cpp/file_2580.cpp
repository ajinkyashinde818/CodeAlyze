#include <bits/stdc++.h>
using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

typedef long long ll;
typedef pair<int, int> pi;

vector<int> v;
int dp[100005][2];
int n;

int main() {
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    const ll INF = 1e16;
    cin>>n;

    ll A[n];
    for (int i=0;i<n;++i) cin>>A[i];
    vector<vector<ll> > dp(n+1, vector<ll> (2));

    dp[1][0] = A[0];
    dp[1][1] = -A[0];
    for (int i=2;i<=n;++i){
        for (int j=0;j<2;++j){
            if (j==0){
                dp[i][j] = max(dp[i-1][0] + A[i-1], dp[i-1][1] - A[i-1]);
            }
            else {
                dp[i][j] = max(dp[i-1][0] - A[i-1], dp[i-1][1] + A[i-1]);
            }
        }
    }
    cout<<dp[n][0]<<endl;

    return 0;
}
