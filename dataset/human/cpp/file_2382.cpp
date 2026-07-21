#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;

const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, -1, 0, +1};
const ll INF = 1e10;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll n; cin >> n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin >> a[i];
    ll cnt = 0, minabs = INF, sum = 0;
    for(ll i=0;i<n;i++){
        if(a[i] < 0) cnt++;
        minabs = min(minabs, abs(a[i]));
        sum += abs(a[i]);
    }
    if(cnt % 2 == 0) cout << sum << endl;
    else cout << sum - 2*minabs << endl;
}
