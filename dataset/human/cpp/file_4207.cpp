#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll beki[35];
ll sum[35];
int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    ll ans = T;
    beki[0] = 1;
    sum[0] = 1;
    for(ll i = 1; i < 35; i++) {
        beki[i] = beki[i - 1] * 3;
        sum[i] = sum[i - 1] + beki[i];
        //cerr << beki[i] << " " << sum[i] << endl;
    }
    for(ll i = 1; i < 34; i++) {
        //cerr << "-----"  << i << "------" << endl;
        ll rest = T - sum[i];
        if(rest < 0) break;
        ll timer = i + 1;
        if(rest < sum[i-1] - 1) continue;
        if(T - sum[i+1] >= sum[i] - 1) continue;
        for(ll j = i; j >= 1; j--) {
            while(rest - beki[j] >= sum[j-1] - 1) {
                timer++;
                rest -= beki[j];
                //cerr << i << " " << j << " " << rest << " " << timer << endl;
            }
        }
        timer += rest;
        //cerr << timer << endl;
        ans = min(ans, timer);
    }
    cout << ans << endl;
    return 0;
}
