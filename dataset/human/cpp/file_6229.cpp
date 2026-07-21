#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;
int main(){
    ll N, C;
    cin >> N >> C;
    pair<ll, ll> sushi[N + 2] = {};
    for(ll i = 0; i < N; i++) cin >> sushi[i + 1].first >> sushi[i + 1].second;
    ll mae = 0;
    ll po[N + 1] = {}, yo[N + 1] = {};
    for(ll i = 0; i < N; i++){
        po[i + 1] = po[i] + sushi[i + 1].second - (sushi[i + 1].first - mae);
        mae = sushi[i + 1].first;
    }
    mae = C;
    for(ll i = 0; i < N; i++){
        yo[i + 1] = yo[i] + sushi[N - i].second - (mae - sushi[N - i].first);
        mae = sushi[N - i].first;
    }
    ll seki[N + 1] = {};
    for(ll i = 0; i < N; i++) seki[i + 1] = max(seki[i], yo[i + 1]);
    ll ans = 0;
    for(ll i = 0; i <= N; i++){
        ans = max(ans, po[i]);
        ans = max(po[i] - sushi[i].first + seki[N - i], ans);
    }
    for(ll i = 0; i < N; i++) seki[i + 1] = max(seki[i], po[i + 1]);
    for(ll i = 0; i <= N; i++){
        ans = max(ans, yo[i]);
        ans = max(yo[i] - (C - sushi[N - i + 1].first) + seki[N - i], ans);
    }
    cout << ans << endl;
    return 0;
}
