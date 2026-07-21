#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int n;
ll vet[100005];
ll dp[100005][2];

ll solve(int pos, int inv){
    if(pos >= n - 1) return (inv ? -vet[pos] : vet[pos]);
    ll &d = dp[pos][inv];
    if(d != -1) return d;
    ll res = solve(pos + 1, 0) + (inv ? -vet[pos] : vet[pos]);
    inv ^= 1;
    return d = max(res, solve(pos + 1, 1) + (inv ? -vet[pos] : vet[pos]));
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> vet[i];
    memset(dp, -1LL, sizeof dp);
    cout << solve(0, 0) << endl;
	return 0;
}
