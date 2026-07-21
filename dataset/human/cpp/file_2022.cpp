#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

const int MAXN = 100000;
const ll inf = 1e9+1;

ll dp[MAXN][2];

ll solve(int i, int sign);

int N;
vector<ll> seq;

int main() {
    ios_base::sync_with_stdio(false);
    for (int i=0; i < MAXN; ++i) {
        dp[i][0] = dp[i][1] = -inf;
    }
    
    cin >> N;
    seq = vector<ll>(N);
    
    for (int i=0; i < N; ++i) cin >> seq[i];
    
    cout << solve(0, 0) << endl;
    return 0;
}


ll solve(int i, int sign) {
    int k = 1;
    if (sign) k = -1;
    
    if (i == N-2) {
        return max((k*seq[i]+seq[i+1]), -(k*seq[i]+seq[i+1]));
    }
    
    if (dp[i][sign] != -inf) return dp[i][sign];

    ll t1 = solve(i+1, 1), t2= solve(i+1, 0);
    
   // cout << i << " " << sign << " " << t1 << " " << t2 << endl;
    
    return (dp[i][sign] = max((-1 * k * seq[i]+ t1), ((k*seq[i] + t2))));
}
